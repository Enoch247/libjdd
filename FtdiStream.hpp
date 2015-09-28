#pragma once
#include <iostream>
#include <string>
#include "FtdiStreamBuf.h"

using namespace std;
namespace jdd{

/*
TODO
*/
class FtdiStream: public iostream
{
    public:

    //constructor uses the following pramameters to figure out what usb device
    //to connect to
    //vid - usb vendor id
    //pid - usb product id
    //description - ftdi description field stored in eeprom
    //serialNum - ftdi serial number feild stored in eeprom
    FtdiStream(unsigned int vid, unsigned int pid, string description = "",
                string serialNum = "");

    //dtor
//    virtual ~FtdiStream();


    protected:
    FtdiStreamBuf sb;
};

}//namespace

