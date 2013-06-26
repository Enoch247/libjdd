/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <stdint.h>
#include <arpa/inet.h> //hton & ntoh
#include <endian.h>

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
inline uint64_t hton(uint64_t i) {return htobe(i);}

//network(TCP/UDP) to host
inline uint8_t  ntoh(uint8_t i)  {return i;}
inline uint16_t ntoh(uint16_t i) {return ntohs(i);}
inline uint32_t ntoh(uint32_t i) {return ntohl(i);}
inline uint64_t ntoh(uint64_t i) {return betoh(i);}

} // end namespace

