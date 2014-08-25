#include "SimpleMovement.h"
#include "Board.h"
using namespace Chess::GameLogic::Movements;

SimpleMovement::SimpleMovement( const Position& from, const Position& to, Board* const board  )
    : Movement( board ),
      m_from( from ),
      m_to( to )
{
}

SimpleMovement::~SimpleMovement()
{
    cout << "~SimpleMovement()\n";
    m_capturedPieces.clear();
}

bool SimpleMovement::doMove()
{

    if ( m_board->isPiece( m_to ) )
    {
        m_capturedPieces.push_back( m_board->pieceAt( m_to ) );
    }

    const bool isPieceMoved = m_board->movePiece( m_from, m_to );

    if ( isPieceMoved )
    {
        ChessPiece* piece = m_board->pieceAt( m_to );

        int currentMoves = m_board->passedMoves( piece );
        m_board->setPassedMoves( piece, ++ currentMoves );
    }

    return isPieceMoved;
}

bool SimpleMovement::undoMove()
{
    ChessPiece* const piece = m_board->pieceAt( m_to );

    bool tmp = m_board->movePiece( m_to, m_from );
    if ( ! tmp )
    {
        return false;
    }

    if ( ! m_capturedPieces.empty() )
    {
        m_board->addPiece( m_capturedPieces.back() );
        m_capturedPieces.pop_back();
    }

    m_board->m_movesCountMap[ piece ] --;

    return true;
}

void SimpleMovement::setFrom( const Position& from )
{
    m_from = from;
}

Position SimpleMovement::getFrom() const
{
    return m_from;
}

void SimpleMovement::setTo( const Position& to )
{
    m_to = to;
}

Position SimpleMovement::getTo() const
{
    return m_to;
}

void SimpleMovement::setBoard( Board* board )
{
    m_board = board;
}

Board* SimpleMovement::board() const
{
    return m_board;
}
