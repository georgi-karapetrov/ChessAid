#include "Movement.h"
#include "Board.h"

using namespace Chess::GameLogic::Movements;

Movement::Movement( Board* const board )
    : m_board( board )
{
}

Movement::~Movement()
{
    cout << "~Movement()\n";
}
