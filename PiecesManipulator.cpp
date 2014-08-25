#include "PiecesManipulator.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

using namespace Chess::GameLogic::GameComponents;

PiecesManipulator::PiecesManipulator( Board* board )
    : m_board( board )
{
}

PiecesManipulator::~PiecesManipulator()
{
    cout << "~PiecesManipulator()\n";
    this->destroy();
}

void PiecesManipulator::destroy()
{
    cout << "PiecesManipulator::destroy()\n";
    while ( ! m_moves.empty() )
    {
        delete m_moves.top();
        m_moves.pop();
    }
}

Error PiecesManipulator::makeAMove( const Position& from, const Position& to, Colour colour )
{
    if ( !m_board->isPiece( from ) )
    {
        return EmptyPosition;
    }

    if ( m_board->pieceAt( from )->colour() != colour )
    {
        return WrongColour;
    }

    //if the figure attempts to move in its allowed movements
    vector< Position > tmp = m_board->pieceAt( from )->allowedMovements();
    unsigned int i = 0;
    bool flag = false;
    while( i < tmp.size() && !flag )
    {
        if ( tmp[ i ] == to )
        {
            flag = true;
        }
        ++ i;
    }

    Movement* movement = new SimpleMovement( from, to, m_board );

    if ( !flag || !movement->doMove() )
    {
        return InvalidDestination;
    }


    m_moves.push( movement );
    return Success;
}

void PiecesManipulator::undo()
{
    if ( !m_moves.empty() )
    {
        m_moves.top()->undoMove();
        m_moves.pop();
    }
}

bool PiecesManipulator::castling( const Colour& colour, const CastlingType& type )
{
    int castlingOffsetKing = 0;
    int castlingOffsetRook = 0;

    ChessPiece* kingPiece = colour == white ? m_board->pieceAt( WHITE_KING_POSITION ) : m_board->pieceAt( BLACK_KING_POSITION );

    Position rookPosition = colour == white ? type == Kingside ? WHITE_K_ROOK_POSITION : WHITE_Q_ROOK_POSITION
                                            : type == Kingside ? BLACK_K_ROOK_POSITION : BLACK_Q_ROOK_POSITION;
    ChessPiece* rookPiece = m_board->pieceAt( rookPosition );

    if ( !m_board->isPiece( WHITE_KING_POSITION )
         || !m_board->isPiece( rookPosition ) )
    {
        return false;
    }

    if ( kingPiece->pieceType() != king || rookPiece->pieceType() != rook )
    {
        return false;
    }

    if ( ! isCastlingAllowed( kingPiece, rookPiece, type ) )
    {
        return false;
    }


    if ( type == Kingside )
    {
        castlingOffsetKing = KSCASTLING_KING_X;
        castlingOffsetRook = KSCASTLING_ROOK_X;
    }
    else
    {
        castlingOffsetKing = QSCASTLING_KING_X;
        castlingOffsetRook = QSCASTLING_ROOK_X;
    }


    //faking movements here
    //resulting in crashing undo
    Movement* kingMovement = new SimpleMovement( kingPiece->position(),
                                                 Position( castlingOffsetKing,
                                                           kingPiece->position().y() ), m_board );
    Movement* rookMovement = new SimpleMovement( rookPiece->position(),
                                                 Position( castlingOffsetRook,
                                                         rookPiece->position().y() ), m_board );
    vector < Movement* > simpleMovements;

    simpleMovements.push_back( rookMovement );
    simpleMovements.push_back( kingMovement );

    m_board->movePiece( kingPiece->position(), Position( castlingOffsetKing, kingPiece->position().y() ) );
    m_board->movePiece( rookPiece->position(), Position( castlingOffsetRook, rookPiece->position().y() ) );


    Movement* castlingMovement = new ComplexMovement( m_board, simpleMovements );

    m_moves.push( castlingMovement );

    return true;
}

bool PiecesManipulator::isCastlingAllowed(ChessPiece* const kingPiece, ChessPiece* const rookPiece, const CastlingType& type )
{
    if ( m_board->passedMoves( kingPiece ) > 0
         || m_board->passedMoves( rookPiece ) > 0 )
    {
        return false;
    }

    Colour colour = kingPiece->colour();
    const vector< ChessPiece* >& enemyPieces = colour == white ? m_board->blackPieces() : m_board->whitePieces();

    if ( type == Kingside )
    {
        for ( int i = kingPiece->position().x() + 1; i <= KSCASTLING_KING_X; ++ i )
        {
            Position position ( i, kingPiece->position().y() );
            bool obstacle = m_board->isObstacle( position, colour );
            bool los = m_board->inLoS( position, enemyPieces );
            if ( obstacle || los )
            {
                return false;
            }
        }
    }
    else // if type == Queenside
    {
        for ( int i = kingPiece->position().x() - 1; i >= QSCASTLING_KING_X; -- i )
        {
            Position position ( i, kingPiece->position().y() );
            if ( m_board->isObstacle( position, colour )
                 || m_board->inLoS( position, enemyPieces ) )
            {
                return false;
            }
        }
    }

    return true;
}
