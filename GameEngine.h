#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Board.h"
#include "PiecesManipulator.h"
#include "Player.h"
#include <string>
#include <vector>

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

namespace Chess{
namespace ChessComponents {
namespace PlayField {
    class Board;
}
}

namespace GameLogic{
namespace GameComponents{

using std::cin;
using std::string;
using namespace Chess::ChessComponents::PlayField;

const int ROOK_OFFSET     = 0;
const int KNIGHT_OFFSET   = 1;
const int BISHOP_OFFSET   = 2;
const int QUEEN_OFFSET    = 3;
const int KING_OFFSET     = 4;
const int VERTICAL_OFFSET = 7;

enum Instruction
{
    Quit,
    Move,
    Undo,
    Pass,
    Castling,
    FastForward,
    Invalid
};

class GameEngine
{
public:
    GameEngine( const int boardWidth      = 8,
                const int boardHeight     = 8,
                const int numberOfPlayers = 2,
                Colour startingColour     = white );
    ~GameEngine();

    void setBoard( Board* const board );
    Board* board() const;

    void addPlayer( Player& player );
    void nextPlayersTurn();

    void parseInstructions( const string& instruction );
    static Instruction instructionFromCode( const char& ch );

    void run();

    void setStandardGame();

private:
    Position fromChessNotation( const char& x, const char& y );
    void setPiecesForStandardGame( const Colour& colour );

    void quit();
       /*seek and*/
    void destroy();

    void pressEnterToContinue();

private:
    Board*            m_board;
    PiecesManipulator m_manipulator;
    vector< Player >  m_players;
    Colour            m_currentPlayerColour;

    bool              m_quit;
};

}
}
}

#endif // GAMEENGINE_H
