/*
 * File:   CommandQueue.h
 * Author: mvaldenegro
 *
 * Created on 11 de agosto de 2011, 11:34 PM
 */

#ifndef EPIC_OPENCL_COMMANDQUEUE_H
#define	EPIC_OPENCL_COMMANDQUEUE_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class CommandQueue {
            public:
                CommandQueue();
                CommandQueue(cl_command_queue queue);
                CommandQueue(const CommandQueue& other);
                ~CommandQueue();



            private:
                cl_command_queue mCommandQueue;

        };

    }
}


#endif	/* EPIC_OPENCL_COMMANDQUEUE_H */

