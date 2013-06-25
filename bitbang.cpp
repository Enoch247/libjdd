/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

//#include <netinet/in.h>
#include <arpa/inet.h> //hton & ntoh
//#include <endian.h>
#include <limits.h>
#include "bitbang.h"

namespace jdd{

//uint8_t& uint_t_base::byte(size_t i)
//{
//    return ( (uint8_t*)this )[i];
//}

//const uint8_t& uint_t_base::byte(size_t i) const
//{
//    return ( (uint8_t*)this )[i];
//}

////==============================================================================

//uint32_nt::uint32_nt()
//{
//}

//uint32_nt::uint32_nt(uint32_t i):
//	data(htonl(i))
//{
//}

//uint32_t uint32_nt::operator = (uint32_t rhv)
//{
//	return data = htonl(rhv);
//}

//uint32_nt::operator uint32_t () const
//{
//	return ntohl(data);
//}

////uint32_nt uint32_nt::operator = (uint32_nt rhv)
////{
////	data = rhv.data;
////	return rhv;
////}

////bool uint32_nt::operator == (const uint32_nt rhv) const
////{
////	return data == rhv.data;
////}

////bool uint32_nt::operator != (const uint32_nt rhv) const
////{
////	return data != rhv.data;
////}

////uint32_nt uint32_nt::operator | (const uint32_nt rhv) const
////{
////	uint32_nt rtn;
////	rtn.data = data | rhv.data;
////	return rtn;
////}

////uint32_nt uint32_nt::operator & (const uint32_nt rhv) const
////{
////	uint32_nt rtn;
////	rtn.data = data & rhv.data;
////	return rtn;
////}

////uint32_nt uint32_nt::operator ~ () const
////{
////	uint32_nt rtn;
////	rtn.data = ~data;
////	return rtn;
////}

//==============================================================================

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

