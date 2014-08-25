#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <vector>
#include <unordered_map>

namespace Chess{
namespace ChessComponents {
namespace PlayField {
    class Board;
    //class ChessPiece;
}
namespace ChessPieces {
    class ChessPiece;
}
}

namespace GameLogic {
namespace Movements {

using namespace Chess::ChessComponents::PlayField;
using namespace Chess::ChessComponents::ChessPieces;

using namespace std;

class Movement
{
public:
    Movement( Board* const board = 0 );
    virtual ~Movement();

    virtual bool doMove() = 0;
    virtual bool undoMove() = 0;

protected:
    Board* m_board;

};

}
}
}

#endif // MOVEMENT_H
