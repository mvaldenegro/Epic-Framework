/*
 * File:   CommandQueue.cpp
 * Author: mvaldenegro
 *
 * Created on 11 de agosto de 2011, 11:34 PM
 */

#include "CommandQueue.h"

namespace Epic {
namespace OpenCL {

    CommandQueue::CommandQueue()
    : mCommandQueue(0)
    {
    }

    CommandQueue::CommandQueue(cl_command_queue queue)
    : mCommandQueue(queue)
    {

    }

    CommandQueue::CommandQueue(const CommandQueue& other)
    : mCommandQueue(other.mCommandQueue)
    {
    }

    CommandQueue::~CommandQueue()
    {
    }
    
    void CommandQueue::flush() const
    {
        clFlush(queueHandle());
    }
    
    void CommandQueue::finish() const
    {
        clFinish(queueHandle());
    }
}
}


