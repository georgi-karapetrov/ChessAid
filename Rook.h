#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

#include <vector>


namespace Chess{
namespace ChessComponents{
namespace PlayField {
    class Board;
}

namespace ChessPieces{

class Rook : public ChessPiece
{
public:
    Rook( const Position& position = Position( 0, 0 ), const Colour& colour = white, Board* const board = 0 );
    ~Rook();

    bool takes( const Position& position );
    vector< Position > allowedMovements();

    ChessPieceType pieceType();
};

}
}
}

#endif // ROOK_H
