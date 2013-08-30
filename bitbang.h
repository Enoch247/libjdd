/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include "NetworkInt.h"
#include "Nill.h"

namespace jdd{


//everything else is pulled in by includes...

//==============================================================================

class BitPtr//it would be better to use a function for this than an object
{
    public:
    BitPtr(uint32_nt *word, int digit);
    bool operator = (bool b);//assingment from bool
    operator bool () const;//assingment to bool

    protected:
    uint32_nt *word;
    uint32_nt bitmask;
};

} // end namespace

