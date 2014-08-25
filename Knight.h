#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "ChessPiece.h"

namespace Chess{
namespace ChessComponents{
namespace ChessPieces{

class Knight : public ChessPiece
{
public:
    Knight( const Position& position, const Colour& colour, Board* board );
    ~Knight();

    bool takes( const Position& position );
    vector< Position > allowedMovements();

    ChessPieceType pieceType();

private:
    void checkAllowedMovements ( int x, int y, vector< Position >& aVector );
};

}

}

}

#endif // KNIGHT_H
