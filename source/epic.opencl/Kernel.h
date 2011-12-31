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

#ifndef EPIC_OPENCL_KERNEL_H
#define	EPIC_OPENCL_KERNEL_H

#include <epic.core/Core.h>
#include <epic.core/ASCIIString.h>

#include <CL/opencl.h>

#include <epic.opencl/Buffer.h>

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
                
                void setArgument(cl_uint argumentIndex, const Buffer& buffer);
                void setArgument(cl_uint argumentIndex, size_t argumentSize, const void *argumentValue);

                void setArgument(cl_uint argumentIndex, cl_char value);
                void setArgument(cl_uint argumentIndex, cl_uchar value);
                void setArgument(cl_uint argumentIndex, cl_short value);
                void setArgument(cl_uint argumentIndex, cl_ushort value);
                void setArgument(cl_uint argumentIndex, cl_int value);
                void setArgument(cl_uint argumentIndex, cl_uint value);
                void setArgument(cl_uint argumentIndex, cl_long value);
                void setArgument(cl_uint argumentIndex, cl_ulong value);

                void setArgument(cl_uint argumentIndex, cl_float value);
                void setArgument(cl_uint argumentIndex, cl_double value);

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

