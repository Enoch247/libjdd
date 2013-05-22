/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <streambuf>
#include <vector>
#include "FtdiWrapper.h"

using namespace std;
namespace jdd{

/*
a streambuf interface for libftdi. see example:

    FtdiStreamBuf ftdibuf(0x0403, 0x6010);
    iostream ftdi(&ftdibuf);

    char character;
    int integer;

    //when sending data, you must send a flush whenever you are ready to
    //actaully send. endl can be used in place of flush if you want to go to a
    //new line and flush at the same time.
    ftdi << character << ineger << flush;
    ftdi >> character >> ineger;
*/
class FtdiStreamBuf: public streambuf
{
    public:

    //constructor uses the following pramameters to figure out what usb device
    //to connect to
    //vid - usb vendor id
    //pid - usb product id
    //description - ftdi description field stored in eeprom
    //serialNum - ftdi serial number feild stored in eeprom
    FtdiStreamBuf(unsigned int vid, unsigned int pid, string description ="",
                  string serialNum ="");

    //dtor
    ~FtdiStreamBuf() throw();


    protected:

    //inherited from streambuf
    virtual int overflow(int);
    virtual int underflow();
    virtual int sync();

    //the device we read/write from
    FtdiWrapper ftdi;

    vector<uint8_t> writeBuf;//all writes go here untill a flush is sent
    uint8_t readBuf;//minimal read buffer since libftdi is already buffering
};

}//namespace
//#endif

