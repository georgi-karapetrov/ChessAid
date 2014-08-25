#ifndef PAWN_H
#define PAWN_H

#include <cmath>
#include <vector>
#include "ChessPiece.h"
#include "Board.h"

namespace Chess{
namespace ChessComponents{
namespace ChessPieces{

class Pawn : public ChessPiece
{
public:
    Pawn( const Position& position, const Colour& Colour, Board* board );

    ~Pawn();

    bool takes( const Position& position );
    vector< Position > allowedMovements();

    void setInitialPosition( const Position& position );
    Position getInitialPosition() const;

    ChessPieceType pieceType();

private:
    bool canAddToMovements( const Position& position ) const;

private:
    Position m_initialPosition;
};

}
}
}

#endif // PAWN_H
