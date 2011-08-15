/* 
 * File:   Buffer.h
 * Author: mvaldenegro
 *
 * Created on 13 de agosto de 2011, 10:25 PM
 */

#ifndef EPIC_OPENCL_BUFFER_H
#define	EPIC_OPENCL_BUFFER_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        
        class Buffer
        {
            public:
                Buffer();
                Buffer(cl_mem buffer);
                Buffer(const Buffer& other);
                ~Buffer();
                
                EPIC_INLINE cl_mem bufferHandle() const
                {
                    return mBuffer;
                }
                
            private:
                cl_mem mBuffer;
        };

    }
}

#endif	/* EPIC_OPENCL_BUFFER_H */

