/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
//#include "..."

namespace jdd{

//zero sized data structure
union Nill{ char nill[0]; };

static_assert( sizeof(Nill) == 0, "sizeof jdd::Nill is not equal to 0 bytes");
} // end namespace

