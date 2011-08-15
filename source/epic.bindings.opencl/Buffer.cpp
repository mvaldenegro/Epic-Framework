/* 
 * File:   Buffer.cpp
 * Author: mvaldenegro
 * 
 * Created on 13 de agosto de 2011, 10:25 PM
 */

#include "Buffer.h"

namespace Epic {
namespace OpenCL {
    Buffer::Buffer()
    : mBuffer(0)
    {
    }

    Buffer::Buffer(cl_mem buffer)
    : mBuffer(buffer)
    {
    }
    
    Buffer::Buffer(const Buffer& other)
    : mBuffer(other.mBuffer)
    {
    }

    Buffer::~Buffer()
    {
    }
}
}
