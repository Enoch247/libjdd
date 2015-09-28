#include "FtdiStreamBuf.hpp"

namespace jdd{

FtdiStreamBuf::FtdiStreamBuf(unsigned int vid, unsigned int pid,
                             string description, string serialNum):
    ftdi(vid, pid, description, serialNum)
{
}

FtdiStreamBuf::~FtdiStreamBuf() throw()
{
}

int FtdiStreamBuf::overflow(int c)
{
    //push data into buffer, growing if needed
    writeBuf.push_back(c);

    return  0;//signal success
}
int FtdiStreamBuf::underflow()
{
    //read next byte from ftdi device
    ftdi.get( (uint8_t*)&readBuf, sizeof(readBuf) );

    //set streambuf's get pointers
    setg( (char*)&readBuf, (char*)&readBuf, (char*)&readBuf + 1 );

    return readBuf;
}
int FtdiStreamBuf::sync()
{
    //write buffer to ftdi device
    ftdi.put( &writeBuf[0], writeBuf.size() );

    //empty buffer
    writeBuf.clear();

    return 0;//signal success
}

}//namespace

