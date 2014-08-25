#include "Bishop.h"
#include "Board.h"

using namespace std;
//using Chess::ChessPieceType;
using namespace Chess::ChessComponents::ChessPieces;

Bishop::Bishop(const Position& position, const Colour& colour, Board* const board )
    : ChessPiece( position, colour, board, 'B' )
{
}

Bishop::~Bishop()
{
    cout << "~Bishop()\n";
}

bool Bishop::takes( const Position& position )
{
   return m_board->isValidPosition( position ) &&
          position.x() - m_position.x() == position.y() - m_position.y();
}

vector<Position> Bishop::allowedMovements()
{
    vector< Position > tmp;
    int i = 1;

    //these bishops' religion prohibits them from moving over obstacles
    //from what I've heard, however, they're hardly obstructed by little children...
    //little boys, especially...

    while ( m_board->isValidPosition( Position( m_position.x() + i, m_position.y() + i ) )
            && !m_board->isObstacle( Position( m_position.x() + i, m_position.y() + i ), m_colour ) )
    {
        tmp.push_back( Position( m_position.x() + i, m_position.y() + i ) );
        i++;
    }

    i = 1;
    while ( m_board->isValidPosition( Position( m_position.x() + i, m_position.y() - i ) )
            && !m_board->isObstacle( Position( m_position.x() + i, m_position.y() - i ), m_colour ) )
    {
        tmp.push_back( Position( m_position.x() + i, m_position.y() - i ) );
        i++;
    }

    i = 1;
    while ( m_board->isValidPosition( Position( m_position.x() - i, m_position.y() + i ) )
            && !m_board->isObstacle( Position( m_position.x() - i, m_position.y() + i ), m_colour ) )
    {
        tmp.push_back( Position( m_position.x() - i, m_position.y() + i ) );
        i++;
    }

    i = 1;
    while ( m_board->isValidPosition( Position( m_position.x() - i, m_position.y() - i ) )
            && !m_board->isObstacle( Position( m_position.x() - i, m_position.y() - i ), m_colour ) )
    {
        tmp.push_back( Position( m_position.x() - i, m_position.y() - i ) );
        i++;
    }

    return tmp;
}

ChessPieceType Bishop::pieceType()
{
    return bishop;
}
