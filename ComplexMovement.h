#ifndef COMPLEXMOVEMENT_H
#define COMPLEXMOVEMENT_H

#include "Movement.h"
#include "SimpleMovement.h"
#include <vector>

namespace Chess{
namespace GameLogic{
namespace Movements{

class SimpleMovement;

class ComplexMovement : public Movement
{
public:
    ComplexMovement( Board* const board,
                     const vector< Movement* >& moves );
    ~ComplexMovement();

    bool doMove();
    bool undoMove();

    void pushMove( Movement* move );
    Movement* popMove();

private:
    vector< Movement* > m_moves;
};

}
}
}

#endif // COMPLEXMOVEMENT_H
