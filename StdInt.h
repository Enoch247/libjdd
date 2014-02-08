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
template<class NativeType, class Encoding> union StdInt;

//Big Endian
typedef StdInt<uint8_t,  BigEndian> uint8_be;
typedef StdInt<uint16_t, BigEndian> uint16_be;
typedef StdInt<uint32_t, BigEndian> uint32_be;
typedef StdInt<uint64_t, BigEndian> uint64_be;

typedef StdInt<int8_t,  BigEndian> int8_be;
typedef StdInt<int16_t, BigEndian> int16_be;
typedef StdInt<int32_t, BigEndian> int32_be;
typedef StdInt<int64_t, BigEndian> int64_be;

//Little Endian
typedef StdInt<uint8_t,  LilEndian> uint8_le;
typedef StdInt<uint16_t, LilEndian> uint16_le;
typedef StdInt<uint32_t, LilEndian> uint32_le;
typedef StdInt<uint64_t, LilEndian> uint64_le;

typedef StdInt<int8_t,  LilEndian> int8_le;
typedef StdInt<int16_t, LilEndian> int16_le;
typedef StdInt<int32_t, LilEndian> int32_le;
typedef StdInt<int64_t, LilEndian> int64_le;

//==============================================================================

template<class NativeType, class Encoding>
union StdInt
{
    public:

    // default constructor
    StdInt()
    {
    }

    // construct from native type
    StdInt(const NativeType& rhv):
        data(Encoding::encode(rhv))
    {
    }

    // copy constructor
    StdInt(const StdInt& rhv):
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

    // access individual bytes that makup the StdInt
    uint8_t& byte(size_t i)
    {
        return buffer[i];
    }

    // access const ref to individual bytes that makup the StdInt
    const uint8_t& byte(size_t i) const
    {
        return buffer[i];
    }

    // assignment from another StdInt
    const StdInt& operator = (const StdInt& rhv)
    {
        data = rhv.data;
        return rhv;
    }

    // bitwise not
    StdInt operator ~ () const
    {
        StdInt rtn;
        rtn.data = ~data;
        return rtn;
    }

    // equal to
    template<typename T, typename E> friend
    bool operator == (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv);

    // not equal too
    template<typename T, typename E> friend
    bool operator != (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv);

    // bitwise or
    template<typename T, typename E> friend
    StdInt<T, E> operator | (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv);

    // bitwise and
    template<typename T, typename E> friend
    StdInt<T, E> operator & (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv);

    // bitwise xor
    template<typename T, typename E> friend
    StdInt<T, E> operator ^ (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv);

    //TODO operator a &= b
    //TODO operator a |= b
    //TODO operator a ^= b

    private:
    NativeType data;
    uint8_t buffer[];
};

//==============================================================================
//stream operators for NewtorkInt

template<typename T1, typename T2>
std::istream& operator >> (std::istream &is, StdInt<T1, T2> &i)
{
    is.read( (char*)&i, sizeof(i) );
    return is;
}

template<typename T1, typename T2>
std::ostream& operator << (std::ostream &os, const StdInt<T1, T2> &i)
{
    os.write( (const char*)&i, sizeof(i) );
    return os;
}

//==============================================================================
//operator overloads for NewtorkInt (these need to be defined as non member
//functions or else compiler has trouble deciding wether to use these or the
//bultin ones that are for the native int type that the StdInts can be cast
//too if doing something like "uint32_nt(0) == 0")

template<typename T, typename E>
bool operator == (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv)
{
    return lhv.data == rhv.data;
}

template<typename T, typename E>
bool operator != (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv)
{
    return lhv.data != rhv.data;
}

template<typename T, typename E>
StdInt<T, E> operator | (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv)
{
    StdInt<T, E> rtn;
    rtn.data = lhv.data | rhv.data;
    return rtn;
}

template<typename T, typename E>
StdInt<T, E> operator & (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv)
{
    StdInt<T, E> rtn;
    rtn.data = lhv.data & rhv.data;
    return rtn;
}

template<typename T, typename E>
StdInt<T, E> operator ^ (const StdInt<T, E>& lhv, const StdInt<T, E>& rhv)
{
    StdInt<T, E> rtn;
    rtn.data = lhv.data ^ rhv.data;
    return rtn;
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

