#include "PositionResolver.h"
#include <climits>

using namespace Chess::GameLogic::GameComponents;

PositionResolver::PositionResolver( Board* const board )
    : m_board ( board )
{
}

void PositionResolver::resolve() //global resolve which won't work, like ever
{
  /*  bool nothingMoved = false;
    long int guardian = INT_MIN;

    while ( ! nothingMoved && guardian < INT_MAX )
    {
        for ( vector< ChessPiece* >::iterator i = m_board->m_pieces.begin(); i != m_board->m_pieces.end(); ++i )
        {
            unsigned int count = 0;
            vector< Position >::iterator j = ( *i )->allowedMovements().begin();
            vector< Position > tmp = ( *i )->allowedMovements();

            nothingMoved = true;
            while ( m_board->m_piecesMap[ ( *j ) ] != 0 && count < ( *i )->allowedMovements().size() )
            {
                m_board->movePiece( ( *i ), tmp[ count ] );
                nothingMoved = false;
                ++j;
                count++;
            }
        }
        guardian++;
    }*/
}
