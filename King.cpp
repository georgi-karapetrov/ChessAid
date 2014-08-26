#include "King.h"
#include "Board.h"

using namespace std;
using namespace Chess::ChessComponents::ChessPieces;

King::King( const Position& position, const Colour& colour, Board* board )
    : ChessPiece( position, colour, board, 'K' )
{
}

King::~King()
{
    cout << "~King()\n";
}

bool King::takes( const Position& position )
{
    return m_board->isValidPosition( position ) &&
           ( abs( m_position.x() - position.x() ) <= 1  &&
             abs( m_position.y() - position.y() ) <= 1 );
}

void King::checkAllowedMovements( const Position& position, vector < Position >& aVector )
{
    //a false king, proven unworthy in war... he is limp, he is blind, but at least he is immortal. And French.
    //again being obstructed is a big deal
    if ( m_board->isValidPosition( position ) && !m_board->isObstacle( position, m_colour ) )
    {
        aVector.push_back( position );
    }
}

bool King::inCheck()
{
    if ( m_colour == white )
    {
        for ( auto iter = m_board->blackPieces().begin(); iter != m_board->blackPieces().end(); ++ iter )
        {
            if ( ( *iter )->takes( m_position ) )
            {
                return true;
            }
        }
    }
    else
    {
        for ( auto iter = m_board->whitePieces().begin(); iter != m_board->whitePieces().end(); ++ iter )
        {
            if ( ( *iter )->takes( m_position ) )
            {
                return true;
            }
        }
    }
    return false;
}

vector< Position > King::allowedMovements()
{
    vector< Position > tmp;

    checkAllowedMovements( Position( m_position.x() - 1, m_position.y() - 1 ), tmp );
    checkAllowedMovements( Position( m_position.x()    , m_position.y() - 1 ), tmp );
    checkAllowedMovements( Position( m_position.x() + 1, m_position.y() - 1 ), tmp );
    checkAllowedMovements( Position( m_position.x() - 1, m_position.y()     ), tmp );
    checkAllowedMovements( Position( m_position.x() + 1, m_position.y()     ), tmp );
    checkAllowedMovements( Position( m_position.x() - 1, m_position.y() + 1 ), tmp );
    checkAllowedMovements( Position( m_position.x()    , m_position.y() + 1 ), tmp );
    checkAllowedMovements( Position( m_position.x() + 1, m_position.y() + 1 ), tmp );

    return tmp;
}

ChessPieceType King::pieceType()
{
    return tKing;
}
