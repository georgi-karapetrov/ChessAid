#include <iostream>
#include "GameEngine.h"

//#include "Rook.h"
//#include "Knight.h"
//#include "Board.h"
//#include "king.h"
//#include "Board.h"
//#include "Pawn.h"
//#include "Queen.h"

#include "Player.h"

enum People
{
    Crazy,
    Ugly,
    Drunk
};

using namespace std;
using namespace Chess;
using namespace Chess::GameLogic::GameComponents;
using namespace Chess::ChessComponents::PlayField;

int main()
{
    GameEngine engine( 8, 8, 2, white );

    //TODO: Castling, Check, Make King only movable figure if in Check

    engine.setStandardGame();
    engine.run();

//    ChessPiece* rook_ = new Rook();
//    delete rook_;

    cout << "\n>Pleased to meet you\n" << endl;

    return 0;
}
