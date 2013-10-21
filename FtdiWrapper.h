/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <string>
#include <stdint.h>
#include <ftdi.h>

using namespace std;
namespace jdd{

/*
this class wraps libftdi function calls to make it a little more c++ friendly
*/
class FtdiWrapper
{
    public:

    //constructor uses the following pramameters to figure out what usb device
    //to connect to
    //vid - usb vendor id
    //pid - usb product id
    //description - ftdi description field stored in eeprom
    //serialNum - ftdi serial number feild stored in eeprom
    FtdiWrapper(unsigned int vid, unsigned int pid, string description ="",
                string serialNum ="");
    
    //dtor
    ~FtdiWrapper();

    //get some bytes from the FTDI interface
    //buffer - a pointer to where the bytes will be stored
    //bufSize - how many bytes to get
    void get(uint8_t *buffer, unsigned int bufSize);

    //get some bytes from the FTDI interface
    //buffer - a pointer to where the bytes will be stored
    //bufSize - the max bytes to get
    //minGet - the minimum bytes to get before returning
    //rtn - the actual number of bytes read
    int get(uint8_t *buffer, unsigned int bufSize, unsigned int minGet);

    //send some bytes to the FTDI interface
    //buffer - a pointer to the bytes that will be sent
    //bufSize - how many bytes to send
    void put(const uint8_t *buffer, unsigned int bufSize);

    //send some bytes to the FTDI interface
    //buffer - a pointer to the bytes that will be sent
    //bufSize - the size of the buffer in bytes
    //minGet - the minimum bytes to send before returning
    //rtn - the actual number of bytes written
    int put(const uint8_t *buffer, unsigned int bufSize, unsigned int minPut);

    protected:
    ftdi_context *ftdiContext;
};

}//namespace

