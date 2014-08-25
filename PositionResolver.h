#ifndef POSITIONRESOLVER_H
#define POSITIONRESOLVER_H

#include "ChessPiece.h"
#include "Board.h"

namespace Chess {

namespace GameLogic{

namespace GameComponents{

class PositionResolver
{
public:
    PositionResolver( Board* const board = 0 );

    Board* m_board;
    void resolve();
};

}
}
}

#endif // POSITIONRESOLVER_H
