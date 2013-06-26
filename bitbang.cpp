/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#include "bitbang.h"

namespace jdd{

BitPtr::BitPtr(uint32_nt *word, int digit):
    word(word)
{
    bitmask = (0x1 << digit);
}

bool BitPtr::operator = (bool rhv)
{
    uint32_t bits = *word;

    if(rhv)
        bits = bits | bitmask; //set bit
    else
        bits = bits & ~bitmask; //clear bit

    *word = bits;

    return rhv;
}

BitPtr::operator bool () const
{
    uint32_t bits = *word;
    return (bits & bitmask);
}

}// namespace

