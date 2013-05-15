/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#include <iostream>
#include "FtdiStream.h"

namespace jdd{

FtdiStream::FtdiStream(unsigned int vid, unsigned int pid,
                       string description, string serialNum):
    iostream(&sb),
    sb(vid, pid, description, serialNum)
{
}

//FtdiStream::~FtdiStream()
//{
//}

}//namespace

