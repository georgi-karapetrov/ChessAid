#include "Pawn.h"

using namespace std;
//using Chess::ChessPieceType;
using namespace Chess::ChessComponents::ChessPieces;

Pawn::Pawn( const Position& position, const Colour& colour, Board* board )
    : ChessPiece( position, colour, board, 'P' ),
      m_initialPosition( position )
{
}

Pawn::~Pawn()
{
    cout << "~Pawn()\n";
}

bool Pawn::takes( const Position& position )
{
    const int offset = m_colour == white ? +1 : -1;

    return m_board->isValidPosition( position )
            && ( abs( m_position.x() - position.x() ) == 1
                 && ( m_position.y() - position.y() == offset ) );
}

vector< Position > Pawn::allowedMovements()
{
    vector< Position > tmp;

    const int offset = m_colour == white ? -1 : +1;

    //maybe if they got paid more they'd do more than move one step forward...
    //and stop if there's a fat guy in front of them

    if ( m_board->isValidPosition( Position ( m_position.x(), m_position.y() + offset ) )
         && !m_board->isPiece( Position ( m_position.x(), m_position.y() + offset ) ) )
    {
        tmp.push_back( Position( m_position.x(), m_position.y() + offset ) );
    }

    if ( m_position == m_initialPosition
         && m_board->isValidPosition( Position( m_position.x(), m_position.y() + offset * 2 ) ) )
    {
        tmp.push_back( Position( m_position.x(), m_position.y() + offset * 2 )  );
    }

    if ( canAddToMovements( Position( m_position.x() + 1, m_position.y() + offset ) ) )
    {
        tmp.push_back( Position( m_position.x() + 1, m_position.y() + offset ) );
    }

    if ( canAddToMovements( Position( m_position.x() - 1, m_position.y() + offset ) ) )
    {
        tmp.push_back( Position( m_position.x() - 1, m_position.y() + offset ) );
    }

    return tmp;
}

void Pawn::setInitialPosition( const Position& position )
{
    m_initialPosition = position;
}

Position Pawn::getInitialPosition() const
{
    return m_initialPosition;
}

bool Pawn::canAddToMovements( const Position& position ) const
{
    bool validPos = m_board->isValidPosition( position );
    bool piece = m_board->isPiece( position );
    bool obstacle = m_board->isObstacle( position, m_colour );

    return validPos && piece && !obstacle;

//    return     m_board->isValidPosition( position )
//           &&  m_board->isPiece( position )
//           && !m_board->isObstacle( position, m_colour );
}

ChessPieceType Pawn::pieceType()
{
    return tPawn;
}
