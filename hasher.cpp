#include "hasher.h"

Hasher::Hasher()
{
}

size_t Hasher::operator() ( Position const& key ) const
{
    return key.getX() + key.getY();
}

