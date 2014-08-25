#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <unordered_map>

namespace Chess{
namespace ChessComponents{
namespace PlayField{

using namespace std;

class Position
{
public:
    Position( const int x = 0, const int y = 0 );
    Position( const Position& other );

    ~Position();

    Position& operator=( const Position& );

    friend istream& operator>>( istream& is, Position& position );
    friend ostream& operator<<( ostream& os, const Position& position );
    bool operator==( const Position& rhs ) const;
    bool operator!=( const Position& rhs) const;

    void setX( const int x );
    int x() const;

    void setY( const int y );
    int y() const;

private:
    void copy( const Position& );

public:
    int m_x;
    int m_y;
};


}
}
}

using namespace Chess::ChessComponents::PlayField;
namespace std
{
   template <>
   struct hash< Position >
   {
       size_t operator ()( const Position& pos ) const
       {
           return pos.x() ^ ( pos.y() << 1 );
       }
   };
}
#endif // POSITION_H
