/* 
 * File:   Kernel.cpp
 * Author: mvaldenegro
 * 
 * Created on 13 de agosto de 2011, 07:34 PM
 */

#include "Kernel.h"
#include "OpenCLException.h"

namespace Epic {
namespace OpenCL {
 
    Kernel::Kernel()
    : mKernel(0)
    {
    }
    
    Kernel::Kernel(cl_kernel kernel)
    : mKernel(kernel)
    {
    }

    Kernel::Kernel(const Kernel& other)
    : mKernel(other.mKernel)
    {
    }

    Kernel::~Kernel()
    {
    }
    
    size_t Kernel::getInfoSize(cl_kernel_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetKernelInfo(kernelHandle(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Kernel::getInfo(cl_kernel_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetKernelInfo(kernelHandle(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }
}
}
