#pragma once

namespace jdd{

// zero sized data structure, useful as a defualt template argument to
// effectively create optional template arguments
union Nill
{
    char nill[0];
};

static_assert( sizeof(Nill) == 0, "sizeof jdd::Nill is not equal to 0 bytes");

} // end namespace

