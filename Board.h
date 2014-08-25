#ifndef BOARD_H
#define BOARD_H

#include "ChessPiece.h"
//#include <iostream>
#include <vector>
#include <unordered_map>

namespace Chess{
namespace ChessComponents{
namespace PlayField{

using std::cout;
using std::endl;

using namespace Chess::ChessComponents::ChessPieces;

class Board
{
public:
    Board( const int width = 8, const int height = 8 );
    Board( const Board& other );

    ~Board();

    void seWidth( const int width );
    int width() const;

    void setHeight( const int height );
    int height() const;

    void addPiece( ChessPiece* piece );
    bool movePiece( const Position& from, const Position& to );

    bool placePieces( vector < ChessPiece* > pieces,
                      unsigned int it);

    bool isValidPosition( const Position& position ) const;

    void initPiecesMap();

    void display();

    Position nextPosition( const Position& position );
    bool isThreat( ChessPiece* piece );
    bool inLoS( const Position& position, vector< ChessPiece* > aVector ) const;

    bool isPiece( const Position& position ) const;
    bool isObstacle( const Position& position, const Colour& colour ) const;

    ChessPiece* pieceAt( const Position& position ) const;

    void setPassedMoves(ChessPiece* piece , int anInteger );
    int passedMoves( ChessPiece* piece ) const;

    void setWhitePieces( vector< ChessPiece* > pieces );
    vector< ChessPiece* > whitePieces() const;

    void setBlackPieces( vector< ChessPiece* > pieces );
    vector< ChessPiece* > blackPieces() const;


private:
    void clearPosition( const Position& position );
    void copy( const Board& other );

public:
    unordered_map< ChessPiece*, int > m_movesCountMap;

private:
    int m_width;
    int m_height;

    vector< ChessPiece* > m_whitePieces;
    vector< ChessPiece* > m_blackPieces;
    unordered_map< Position, ChessPiece* > m_piecesMap;
};

}
}
}

#endif // BOARD_H
