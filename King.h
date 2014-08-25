#ifndef KING_H
#define KING_H

#include <cmath>
#include <vector>

#include "ChessPiece.h"
#include "Queen.h"

// comment

namespace Chess{
namespace ChessComponents{
namespace ChessPieces{

class King : public ChessPiece
{
public:
    King( const Position& position, const Colour& colour, Board* board );
    ~King();

    bool takes( const Position& position );
    vector< Position > allowedMovements();

    ChessPieceType pieceType();

private:
    void checkAllowedMovements( const Position& position, vector< Position >& aVector );
    bool inCheck();
};

}
}
}

#endif // KING_H
