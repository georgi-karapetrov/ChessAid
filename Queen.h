#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include "ChessPiece.h"
#include "Position.h"
#include "Rook.h"
#include "Bishop.h"

namespace Chess{

namespace ChessComponents{

class Rook;

namespace ChessPieces{

class Queen : public ChessPiece
{
public:
    Queen( const Position& position, const Colour& colour, Board* const board  );
    ~Queen();

    bool takes( const Position& position );
    vector< Position > allowedMovements();

    void setPosition( const Position& position );

    ChessPieceType pieceType();

private:
    Rook*   m_rook;
    Bishop* m_bishop;
};

}
}
}

#endif // QUEEN_H
