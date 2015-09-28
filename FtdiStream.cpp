#include <iostream>
#include "FtdiStream.hpp"

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

