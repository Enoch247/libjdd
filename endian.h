// a c++ friendlier version of endian.h provided by most *nix systems

#pragma once
#include <stdint.h>
#include <arpa/inet.h> //hton & ntoh
#include <endian.h>

namespace jdd{

//host to big endian (unsigned)
inline uint8_t  htobe(uint8_t i)  {return i;}
inline uint16_t htobe(uint16_t i) {return htobe16(i);}
inline uint32_t htobe(uint32_t i) {return htobe32(i);}
inline uint64_t htobe(uint64_t i) {return htobe64(i);}

//big endian to host (unsigned)
inline uint8_t  betoh(uint8_t i)  {return i;}
inline uint16_t betoh(uint16_t i) {return be16toh(i);}
inline uint32_t betoh(uint32_t i) {return be32toh(i);}
inline uint64_t betoh(uint64_t i) {return be64toh(i);}

//host to big endian (signed)
inline int8_t  htobe(int8_t i)  {return i;}
inline int16_t htobe(int16_t i) {return htobe16(i);}
inline int32_t htobe(int32_t i) {return htobe32(i);}
inline int64_t htobe(int64_t i) {return htobe64(i);}

//big endian to host (signed)
inline int8_t  betoh(int8_t i)  {return i;}
inline int16_t betoh(int16_t i) {return be16toh(i);}
inline int32_t betoh(int32_t i) {return be32toh(i);}
inline int64_t betoh(int64_t i) {return be64toh(i);}

//------------------------------------------------------------------------------

//host to little endian (unsigned)
inline uint8_t  htole(uint8_t i)  {return i;}
inline uint16_t htole(uint16_t i) {return htole16(i);}
inline uint32_t htole(uint32_t i) {return htole32(i);}
inline uint64_t htole(uint64_t i) {return htole64(i);}

//little endian to host (unsigned)
inline uint8_t  letoh(uint8_t i)  {return i;}
inline uint16_t letoh(uint16_t i) {return le16toh(i);}
inline uint32_t letoh(uint32_t i) {return le32toh(i);}
inline uint64_t letoh(uint64_t i) {return le64toh(i);}

//host to little endian (signed)
inline int8_t  htole(int8_t i)  {return i;}
inline int16_t htole(int16_t i) {return htole16(i);}
inline int32_t htole(int32_t i) {return htole32(i);}
inline int64_t htole(int64_t i) {return htole64(i);}

//little endian to host (signed)
inline int8_t  letoh(int8_t i)  {return i;}
inline int16_t letoh(int16_t i) {return le16toh(i);}
inline int32_t letoh(int32_t i) {return le32toh(i);}
inline int64_t letoh(int64_t i) {return le64toh(i);}

//------------------------------------------------------------------------------

//host to network(TCP/UDP) (unsigned)
inline uint8_t  hton(uint8_t i)  {return i;}
inline uint16_t hton(uint16_t i) {return htons(i);}
inline uint32_t hton(uint32_t i) {return htonl(i);}
inline uint64_t hton(uint64_t i) {return htobe(i);}

//network(TCP/UDP) to host (unsigned)
inline uint8_t  ntoh(uint8_t i)  {return i;}
inline uint16_t ntoh(uint16_t i) {return ntohs(i);}
inline uint32_t ntoh(uint32_t i) {return ntohl(i);}
inline uint64_t ntoh(uint64_t i) {return betoh(i);}

//host to network(TCP/UDP) (signed)
inline int8_t  hton(int8_t i)  {return i;}
inline int16_t hton(int16_t i) {return htons(i);}
inline int32_t hton(int32_t i) {return htonl(i);}
inline int64_t hton(int64_t i) {return htobe(i);}

//network(TCP/UDP) to host (signed)
inline int8_t  ntoh(int8_t i)  {return i;}
inline int16_t ntoh(int16_t i) {return ntohs(i);}
inline int32_t ntoh(int32_t i) {return ntohl(i);}
inline int64_t ntoh(int64_t i) {return betoh(i);}

} // end namespace

