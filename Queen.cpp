#include "Queen.h"
#include "Board.h"

using namespace std;
//using Chess::ChessPieceType;
using namespace Chess::ChessComponents::ChessPieces;

Queen::Queen( const Position& position, const Colour& colour, Board* const board )
    : ChessPiece( position, colour, board, 'Q' ),
      m_rook( 0 ),
      m_bishop( 0 )
{
    m_rook = new Rook( position, colour, board );
    m_bishop = new Bishop( position, colour, board );
}

Queen::~Queen()
{
    cout << "~Queen()\n";
    delete m_rook;
    delete m_bishop;
}

bool Queen::takes( const Position& position )
{
    return m_board->isValidPosition( position ) &&
           ( m_rook->takes( position ) ||
             m_bishop->takes( position ) );
}

vector<Position> Queen::allowedMovements()
{
    //a genuine tryhard queen to pair up with the coward king
    //still the better version of him, this two-faced bitch has problems with obstacles,
    //as well as a few underage pregnancies and appearances on MTV's Sixteen and Pregnant.
    //what a surprise

    vector< Position > tmp;
    vector< Position > tmpBishop;

    tmp = m_rook->allowedMovements();
    tmpBishop = m_bishop->allowedMovements();

    tmp.reserve( tmp.size() + tmpBishop.size() );
    tmp.insert( tmp.end(), tmpBishop.begin(), tmpBishop.end() );

    return tmp;
}

void Queen::setPosition( const Position& position )
{
    ChessPiece::setPosition( position );

    m_rook->setPosition( position );
    m_bishop->setPosition( position );
}

ChessPieceType Queen::pieceType()
{
    return queen;
}
