/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <iostream>
#include <stdint.h>
#include <arpa/inet.h> //hton & ntoh
#include <endian.h>

using namespace std;
namespace jdd{

//host to big endian
inline uint8_t  htobe(uint8_t i)  {return i;}
inline uint16_t htobe(uint16_t i) {return htobe16(i);}
inline uint32_t htobe(uint32_t i) {return htobe32(i);}
inline uint64_t htobe(uint64_t i) {return htobe64(i);}

//big endian to host
inline uint8_t  betoh(uint8_t i)  {return i;}
inline uint16_t betoh(uint16_t i) {return be16toh(i);}
inline uint32_t betoh(uint32_t i) {return be32toh(i);}
inline uint64_t betoh(uint64_t i) {return be64toh(i);}

//------------------------------------------------------------------------------

//host to little endian
inline uint8_t  htole(uint8_t i)  {return i;}
inline uint16_t htole(uint16_t i) {return htole16(i);}
inline uint32_t htole(uint32_t i) {return htole32(i);}
inline uint64_t htole(uint64_t i) {return htole64(i);}

//little endian to host
inline uint8_t  letoh(uint8_t i)  {return i;}
inline uint16_t letoh(uint16_t i) {return le16toh(i);}
inline uint32_t letoh(uint32_t i) {return le32toh(i);}
inline uint64_t letoh(uint64_t i) {return le64toh(i);}

//------------------------------------------------------------------------------

//host to network(TCP/UDP)
inline uint8_t  hton(uint8_t i)  {return i;}
inline uint16_t hton(uint16_t i) {return htons(i);}
inline uint32_t hton(uint32_t i) {return htonl(i);}
//inline uint64_t hton(uint64_t i);

//network(TCP/UDP) to host
inline uint8_t  ntoh(uint8_t i)  {return i;}
inline uint16_t ntoh(uint16_t i) {return ntohs(i);}
inline uint32_t ntoh(uint32_t i) {return ntohl(i);}
//inline uint64_t ntoh(uint64_t i);

//==============================================================================

struct BigEndianNet
{
    template<typename T>
    static inline T host_to_net(T t) {return htobe(t);}

    template<typename T>
    static inline T net_to_host(T t) {return betoh(t);}
};

//------------------------------------------------------------------------------

struct LilEndianNet
{
    template<typename T>
    static inline T host_to_net(T t) {return htole(t);}

    template<typename T>
    static inline T net_to_host(T t) {return letoh(t);}
};

//------------------------------------------------------------------------------

template<class NativeType, class Endianess = BigEndianNet>
union uint_nt
{
    public:

    // ctor
    uint_nt()
    {
    }

    // ctor
    uint_nt(NativeType rhv)
    {
        *this = rhv;
    }

    // for assignment to native type
    NativeType operator = (NativeType rhv)
    {
        data = Endianess::host_to_net(rhv);
        return rhv;
    }

    // for assignment from native type
    operator NativeType () const
    {
        return Endianess::net_to_host(data);
    }

    // other operators to improve preformance - TODO
//    uint32_nt operator = (uint32_nt);
//    bool operator == (const uint32_nt) const;
//    bool operator != (const uint32_nt) const;
//    uint32_nt operator | (const uint32_nt) const;
//    uint32_nt operator & (const uint32_nt) const;
//    uint32_nt operator ~ () const;

//    uint8_t& byte(size_t i);
//    const uint8_t& byte(size_t i) const;

    private:
    NativeType data;
};

typedef uint_nt<uint8_t>  uint8_nt;
typedef uint_nt<uint16_t> uint16_nt;
typedef uint_nt<uint32_t> uint32_nt;
typedef uint_nt<uint64_t> uint64_nt;


//------------------------------------------------------------------------------

template<typename T1, typename T2>
istream& operator >> (istream &is, uint_nt<T1, T2> &i)
{
    is.read( (char*)&i, sizeof(i) );
    return is;
}

template<typename T1, typename T2>
ostream& operator << (ostream &os, const uint_nt<T1, T2> &i)
{
    os.write( (const char*)&i, sizeof(i) );
    return os;
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

} // end namespace

