#include "Player.h"
#include "ChessPiece.h"
#include "Board.h"

using namespace Chess;
using namespace Chess::GameLogic::GameComponents;

Player::Player( Board* const board, const Colour& playsWith )
    : m_colour( playsWith ),
      m_board( board )
{
}

void Player::setColour( const Colour& colour )
{
    m_colour = colour;
}

Colour Player::colour() const
{
    return m_colour;
}

void Player::setBoard( Board* const board )
{
    m_board = board;
}

Board* Player::board() const
{
    return m_board;
}

bool Player::playsWith( const Colour& colour )
{
    return m_colour == colour;
}
