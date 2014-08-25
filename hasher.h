#ifndef HASHER_H
#define HASHER_H
#include "position.h"

class Hasher
{
public:
    Hasher();
    size_t operator()(Position const& key) const;
};

#endif // HASHER_H
