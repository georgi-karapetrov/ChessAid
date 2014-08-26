#include "Knight.h"
#include "Board.h"

#include <cmath>
#include <algorithm>

using namespace std;
//using Chess::ChessPieceType;
using namespace Chess::ChessComponents::ChessPieces;

Knight::Knight( const Position& position, const Colour& colour, Board* board ) :
    ChessPiece( position, colour, board, 'N' )
{
}

Knight::~Knight()
{
    cout << "~Knight()\n";
}

bool Knight::takes( const Position& position )
{
    return m_board->isValidPosition( position ) &&
           ( ( ( abs( m_position.x() - position.x() ) == 1 ) &&
             ( abs( m_position.y() - position.y() ) == 2 ) ) ||
           ( ( abs( m_position.x() - position.x() ) == 2 ) &&
             ( abs( m_position.y() - position.y() ) == 1 ) ) );
}

void Knight::checkAllowedMovements ( int x, int y, vector< Position >& aVector )
{
    //no one is a match for the righteous knight
    //petty obstacles cannot prevent him from jumping to his death

    if ( m_board->isValidPosition( Position ( x, y ) )
         && !m_board->isObstacle( Position( x, y ), m_colour ))
    {
        aVector.push_back( Position( x, y ) );
    }
}

vector< Position > Knight::allowedMovements()
{
    vector< Position > tmp;

    checkAllowedMovements( m_position.x() - 2, m_position.y() - 1, tmp );
    checkAllowedMovements( m_position.x() - 2, m_position.y() + 1, tmp );
    checkAllowedMovements( m_position.x() - 1, m_position.y() - 2, tmp );
    checkAllowedMovements( m_position.x() - 1, m_position.y() + 2, tmp );
    checkAllowedMovements( m_position.x() + 2, m_position.y() - 1, tmp );
    checkAllowedMovements( m_position.x() + 2, m_position.y() + 1, tmp );
    checkAllowedMovements( m_position.x() + 1, m_position.y() + 2, tmp );
    checkAllowedMovements( m_position.x() + 1, m_position.y() - 2, tmp );

    return tmp;
}

ChessPieceType Knight::pieceType()
{
    return tKnight;
}
