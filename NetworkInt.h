/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <iostream>
#include <stdint.h>
#include "endian.h"

namespace jdd{

//forwad declarations
class BigEndian;
class LilEndian;
template<class NativeType, class Encoding> union NetworkInt;

//unsigned
typedef NetworkInt<uint8_t,  BigEndian> uint8_nt;
typedef NetworkInt<uint16_t, BigEndian> uint16_nt;
typedef NetworkInt<uint32_t, BigEndian> uint32_nt;
typedef NetworkInt<uint64_t, BigEndian> uint64_nt;

//signed
typedef NetworkInt<int8_t,  BigEndian> int8_nt;
typedef NetworkInt<int16_t, BigEndian> int16_nt;
typedef NetworkInt<int32_t, BigEndian> int32_nt;
typedef NetworkInt<int64_t, BigEndian> int64_nt;

//==============================================================================

template<class NativeType, class Encoding>
union NetworkInt
{
    public:

    // default constructor
    NetworkInt()
    {
    }

    // construct from native type
    NetworkInt(const NativeType& rhv):
        data(Encoding::encode(rhv))
    {
    }

    // copy constructor
    NetworkInt(const NetworkInt& rhv):
        data(rhv.data)
    {
    }

    // assignment from native type
    NativeType operator = (const NativeType& rhv)
    {
        data = Encoding::encode(rhv);
        return rhv;
    }

    // cast to native type
    operator NativeType () const
    {
        return Encoding::decode(data);
    }

    // access individual bytes that makup the NetworkInt
    uint8_t& byte(size_t i)
    {
        return bytes[i];
    }

    // access const ref to individual bytes that makup the NetworkInt
    const uint8_t& byte(size_t i) const
    {
        return bytes[i];
    }


    // other operator overloads to improve preformance

    NetworkInt operator = (const NetworkInt& rhv)
    {
        data = rhv.data;
        return rhv;
    }

    bool operator == (const NetworkInt& rhv) const
    {
        return data == rhv.data;
    }

    bool operator != (const NetworkInt& rhv) const
    {
        return data != rhv.data;
    }

    NetworkInt operator | (const NetworkInt& rhv) const
    {
        NetworkInt rtn;
        rtn.data = data | rhv.data;
        return rtn;
    }

    uint32_nt operator & (const NetworkInt& rhv) const
    {
        NetworkInt rtn;
        rtn.data = data & rhv.data;
        return rtn;
    }

    uint32_nt operator ~ () const
    {
        NetworkInt rtn;
        rtn.data = ~data;
        return rtn;
    }


    private:
    NativeType data;
    uint8_t bytes[];
};

//==============================================================================
//stream operators for NewtorkInt

template<typename T1, typename T2>
std::istream& operator >> (std::istream &is, NetworkInt<T1, T2> &i)
{
    is.read( (char*)&i, sizeof(i) );
    return is;
}

template<typename T1, typename T2>
std::ostream& operator << (std::ostream &os, const NetworkInt<T1, T2> &i)
{
    os.write( (const char*)&i, sizeof(i) );
    return os;
}

//==============================================================================
//encodings

struct BigEndian
{
    template<typename T>
    static inline T encode(T t) {return htobe(t);}

    template<typename T>
    static inline T decode(T t) {return betoh(t);}
};

//------------------------------------------------------------------------------

struct LilEndian
{
    template<typename T>
    static inline T encode(T t) {return htole(t);}

    template<typename T>
    static inline T decode(T t) {return letoh(t);}
};

} // end namespace

