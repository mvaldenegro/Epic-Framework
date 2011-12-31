/*
 * Copyright (C) 2011 Matias Valdenegro <matias.valdenegro@gmail.com>
 * This file is part of Epic Framework.
 *
 * Epic Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Epic Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Epic Framework.  If not, see <http://www.gnu.org/licenses/>.
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
    
    void Kernel::setArgument(cl_uint argumentIndex, const Buffer& buffer)
    {
        cl_mem buf = buffer.bufferHandle();

        setArgument(argumentIndex, sizeof(cl_mem), &buf);
    }

    void Kernel::setArgument(cl_uint argumentIndex, size_t argumentSize, const void *argumentValue)
    {
        cl_int err = 0;

        err = clSetKernelArg(kernelHandle(), argumentIndex, argumentSize, argumentValue);

        EPIC_OPENCL_CHECK_ERROR(err)
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
