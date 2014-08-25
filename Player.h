#ifndef PLAYER_H
#define PLAYER_H

#include "ChessPiece.h"
#include "PiecesManipulator.h"

#include <string>

namespace Chess{
namespace ChessComponents {
namespace PlayField {
    class Board;
}
}

namespace GameLogic{
namespace GameComponents{

using namespace Chess::ChessComponents::PlayField;

class Player
{
public:
    Player( Board* const board = 0, const Colour& playsWith = white );

    void setColour( const Colour& colour );
    Colour colour() const;

    void setBoard( Board* const board );
    Board* board() const;

    bool playsWith( const Colour& colour );

private:
    Colour m_colour;
    Board* m_board;
};

}
}
}

#endif // PLAYER_H
