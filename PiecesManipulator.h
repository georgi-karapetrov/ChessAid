#ifndef PIECESMANIPULATOR_H
#define PIECESMANIPULATOR_H

#include "Board.h"
#include "ChessPiece.h"
#include "Movement.h"
#include "SimpleMovement.h"
#include "ComplexMovement.h"

#include <stack>

namespace Chess {
namespace ChessComponents {
namespace PlayField {
    class Board;
}
}

namespace GameLogic {
namespace GameComponents{

using namespace Chess::GameLogic::Movements;
using namespace Chess::ChessComponents::ChessPieces;

enum Error
{
    WrongColour,
    EmptyPosition,
    Success,
    InvalidDestination,
    ReachedEnd
};

enum CastlingType
{
    Kingside,
    Queenside
};

const int KSCASTLING_KING_X = 6;
const int KSCASTLING_ROOK_X = 5;

const int QSCASTLING_KING_X = 2;
const int QSCASTLING_ROOK_X = 3;

const Position WHITE_KING_POSITION = Position( 4, 7 );
const Position BLACK_KING_POSITION = Position( 4, 0 );

const Position WHITE_K_ROOK_POSITION = Position( 7, 7 );
const Position WHITE_Q_ROOK_POSITION = Position( 0, 7 );

const Position BLACK_K_ROOK_POSITION = Position( 7, 0 );
const Position BLACK_Q_ROOK_POSITION = Position( 0, 0 );

class PiecesManipulator
{
public:
    PiecesManipulator( Board* board = 0 );
    ~PiecesManipulator();

    void undo();

    Error makeAMove( const Position& from, const Position& to , Colour colour );

    bool isCastlingAllowed( ChessPiece* const kingPiece, ChessPiece* const rookPiece, const CastlingType& type );
    bool castling( const Colour& colour, const CastlingType& type );

    void destroy();

private:
    stack< Movement* > m_moves;
    Colour             m_currentColour;
    Board*             m_board;
};

}
}
}

#endif // PIECESMANIPULATOR_H
