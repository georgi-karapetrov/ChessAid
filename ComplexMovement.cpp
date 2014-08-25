#include "ComplexMovement.h"

using namespace Chess::GameLogic::Movements;

ComplexMovement::ComplexMovement(Board* const board = 0,
                                  const vector<Movement *>& moves = vector< Movement* >() )//I hope this is  an empty vector,
                                                                                    //doesn't work thew Gope way
    : Movement( board ),
      m_moves( moves )
{
}

ComplexMovement::~ComplexMovement()
{
    cout << "~ComplexMovement()\n";
    for ( auto iter = m_moves.begin(); iter != m_moves.end(); ++ iter )
    {
        delete *iter;
    }
}

bool ComplexMovement::doMove()
{
    for ( auto i = m_moves.begin(); i != m_moves.end(); ++i )
    {
        ( *i )->doMove();
    }
    return true;
}

bool ComplexMovement::undoMove()
{
    for ( int i = m_moves.size() - 1; i >= 0 ; -- i )
    {
       m_moves[ i ]->undoMove();
       delete m_moves[ i ];
    }
    return true;
}

void ComplexMovement::pushMove( Movement* move )
{
    m_moves.push_back( move );
}

Movement* ComplexMovement::popMove()
{
    Movement* tmp = m_moves.back();
    m_moves.pop_back();
    return tmp;
}
