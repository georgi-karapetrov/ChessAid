#ifndef SIMPLEMOVEMENT_H
#define SIMPLEMOVEMENT_H

#include "Movement.h"
#include "Position.h"

using namespace std;

namespace Chess {
namespace ChessComponents {
namespace PlayField {
    class Board;
}

}

namespace GameLogic {
namespace Movements {

using namespace Chess::ChessComponents::ChessPieces;
using namespace Chess::ChessComponents::PlayField;

class SimpleMovement : public Movement
{
public:
    SimpleMovement( const Position& from = Position( 0, 0 ),
                    const Position& to   = Position( 0, 1 ),
                    Board* const   board = 0 );
    ~SimpleMovement();

    bool doMove();
    bool undoMove();

    void setFrom( const Position& from );
    Position getFrom() const;

    void setTo( const Position& to );
    Position getTo() const;

    void setBoard( Board* board );
    Board* board() const;

private:
    Position m_from;
    Position m_to;
    
    vector< ChessPiece* > m_capturedPieces;
};

}
}
}

#endif // SIMPLEMOVEMENT_H
