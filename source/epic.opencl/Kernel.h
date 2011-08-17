/* 
 * File:   Kernel.h
 * Author: mvaldenegro
 *
 * Created on 13 de agosto de 2011, 07:34 PM
 */

#ifndef EPIC_OPENCL_KERNEL_H
#define	EPIC_OPENCL_KERNEL_H

#include <epic.core/Core.h>
#include <epic.core/ASCIIString.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Kernel
        {
            public:
                Kernel();
                Kernel(cl_kernel kernel);
                Kernel(const Kernel& orig);
                ~Kernel();
                
                EPIC_INLINE cl_kernel kernelHandle() const
                {
                    return mKernel;
                }
                
                EPIC_INLINE Epic::Core::ASCIIString functionName() const
                {
                    return getInfoString(CL_KERNEL_FUNCTION_NAME);
                }
                
                EPIC_INLINE cl_uint numberOfArguments() const
                {
                    return getInfoUInt(CL_KERNEL_NUM_ARGS);
                }
                
                EPIC_INLINE Epic::Core::ASCIIString getInfoString(cl_kernel_info paramName) const
                {
                    size_t length = getInfoSize(paramName);
                    char *str = new char[length];

                    getInfo(paramName, length, str);

                    return Epic::Core::ASCIIString::wrap(str);
                }
                
                EPIC_INLINE cl_uint getInfoUInt(cl_kernel_info paramName) const
                {
                    cl_uint ret = 0;
                    
                    getInfo(paramName, sizeof(cl_uint), &ret);
                    
                    return ret;
                }
                
                size_t getInfoSize(cl_kernel_info paramName) const;
                void getInfo(cl_kernel_info paramName, size_t paramValueSize, void *paramValue) const;
                
            private:
                cl_kernel mKernel;
        };

    }
}

#endif	/* EPIC_OPENCL_KERNEL_H */

