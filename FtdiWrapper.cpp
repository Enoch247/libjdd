/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "FtdiWrapper.h"

namespace jdd{

FtdiWrapper::FtdiWrapper(unsigned int vid, unsigned int pid, string description,
                         string serialNum)
{
    try
    {
        //construct connection context
        ftdiContext = ftdi_new();
        if(ftdiContext == NULL)
            throw runtime_error("unable to initialize ftdi driver");

        //open connection
        const char *desc = ( description.empty() ? NULL : description.c_str() );
        const char *serial = ( serialNum.empty() ? NULL : serialNum.c_str() );
        int rtn = ftdi_usb_open_desc(ftdiContext, vid, pid, desc, serial);
        if(rtn < 0)
        {
            stringstream msg;
            msg << "unable to open ftdi connection: ";
            msg << ftdi_get_error_string(ftdiContext);
//            msg << " (Do you have sufficient privileges to access the usb bus? Is the device connected?)";
            throw runtime_error( msg.str() );
        }
    }
    catch(...)
    {
        ftdi_free(ftdiContext);
        throw;
    }
}

FtdiWrapper::~FtdiWrapper()
{
    //close connection
    int rtn = ftdi_usb_close(ftdiContext);
    if(rtn < 0) cerr << ftdi_get_error_string(ftdiContext) << endl;

    //free connection context
    ftdi_free(ftdiContext);
}

void FtdiWrapper::put(const uint8_t *buffer, unsigned int bufSize)
{
    put(buffer, bufSize, bufSize);
}

int FtdiWrapper::put(const uint8_t *buffer, unsigned int bufSize, unsigned int minPut)
{
    unsigned int bytesWritten;
//    unsigned int trys = 0;
    int status;

    do
    {
        //TODO: casting away const is BAD
        //usb write
        status = ftdi_write_data(ftdiContext, const_cast<uint8_t*>(buffer), bufSize);

        //check for usb errors
        if(status < 0)
            throw runtime_error( ftdi_get_error_string(ftdiContext) );

        bytesWritten += status;//keep track of how much we sent
        buffer += status;//move buffer pointer
        bufSize -= status;//adjust buffer size

        //TODO: progressively sleep?

//        trys ++;
//        if(trys > 10)
//            throw runtime_error("timeout occured durring write to usb");

    }
    while(bytesWritten < minPut);

    return bytesWritten;
}

void FtdiWrapper::get(uint8_t *buffer, unsigned int bufSize)
{
    get(buffer, bufSize, bufSize);
}

int FtdiWrapper::get(uint8_t *buffer, unsigned int bufSize, unsigned int minGet)
{
    unsigned int bytesRead;
//    unsigned int trys = 0;
    int status;

    do
    {
        //usb read
        status = ftdi_read_data(ftdiContext, buffer, bufSize);

        //check for usb errors
        if(status < 0)
            throw runtime_error( ftdi_get_error_string(ftdiContext) );

        bytesRead += status;//keep track of how much we got
        buffer += status;//move buffer pointer
        bufSize -= status;//adjust buffer size

        //TODO: progressively sleep?

//        trys ++;
//        if(trys > 10)
//            throw runtime_error("timeout occured durring read to usb");

    }
    while(bytesRead < minGet);

    return bytesRead;
}

}//namespace

