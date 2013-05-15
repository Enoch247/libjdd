/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <stdint.h>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
namespace jdd{

#pragma pack(push,1)

class uint_t_base
{
    public:
    uint8_t& byte(size_t i);
    const uint8_t& byte(size_t i) const;
};

//==============================================================================

// UnsignedINT8bits_NetworkType (8 bit big endian int)
class uint8_nt : public uint_t_base
{
    public:

    // ctors / dtor
    uint8_nt();
    uint8_nt(uint8_t);

    // for assignment to/from a regular uint16_t
    uint8_t operator = (uint8_t);
    operator uint8_t () const;

    private:
    uint8_t data;
};

istream& operator >> (istream &is, uint8_nt &rhv);
ostream& operator << (ostream &os, const uint8_nt &rhv);

//==============================================================================

// UnsignedINT16bits_NetworkType (16 bit big endian int)
class uint16_nt : public uint_t_base
{
    public:

    // ctors / dtor
    uint16_nt();
    uint16_nt(uint16_t);

    // for assignment to/from a regular uint16_t
    uint16_t operator = (uint16_t);
    operator uint16_t () const;

    private:
    uint16_t data;
};

istream& operator >> (istream &is, uint16_nt &rhv);
ostream& operator << (ostream &os, const uint16_nt &rhv);

//==============================================================================

// UnsignedINT32bits_NetworkType (32 bit big endian int)
class uint32_nt : public uint_t_base
{
    public:

    // ctors / dtor
    uint32_nt();
    uint32_nt(uint32_t);

    // for assignment to/from a regular uint32_t
    uint32_t operator = (uint32_t);
    operator uint32_t () const;

    // other operators to improve preformance - I don't think these really help
//    uint32_nt operator = (uint32_nt);
//    bool operator == (const uint32_nt) const;
//    bool operator != (const uint32_nt) const;
//    uint32_nt operator | (const uint32_nt) const;
//    uint32_nt operator & (const uint32_nt) const;
//    uint32_nt operator ~ () const;

    private:
    uint32_t data;
};

istream& operator >> (istream &is, uint32_nt &rhv);
ostream& operator << (ostream &os, const uint32_nt &rhv);

//==============================================================================

template<typename T>
vector<uint8_t>& operator << (vector<uint8_t> &buffer, const T &rhv)
{
    for(unsigned int i = 0; i < sizeof(rhv); i++)
        buffer.push_back( ( (uint8_t*)&rhv )[i] );
    return buffer;
}

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

#pragma pack(pop)

} // end namespace

