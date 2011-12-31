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

#ifndef EPIC_OPENCL_PROGRAM_H
#define	EPIC_OPENCL_PROGRAM_H

#include <epic.core/Core.h>
#include <epic.core/ASCIIString.h>
#include <epic.core/Array.h>

#include <CL/opencl.h>

#include <epic.opencl/Device.h>
#include <epic.opencl/Kernel.h>

namespace Epic {
    namespace OpenCL {

        class Program
        {
            public:
                Program();
                Program(cl_program program);
                Program(const Program& other);
                ~Program();

                EPIC_INLINE cl_program programHandle() const
                {
                    return mProgram;
                }

                EPIC_INLINE cl_uint numberOfDevices() const
                {
                    cl_uint ret = 0;

                    getInfo(CL_PROGRAM_NUM_DEVICES, sizeof(cl_uint), &ret);

                    return ret;
                }

                Epic::Core::Array<Device> devices() const;
                
                EPIC_INLINE Epic::Core::ASCIIString source() const
                {
                    size_t sourceLength = getInfoSize(CL_PROGRAM_SOURCE);
                    char *str = new char[sourceLength];
                    
                    getInfo(CL_PROGRAM_SOURCE, sourceLength, str);
                    
                    return Epic::Core::ASCIIString::wrap(str);
                }

                size_t getInfoSize(cl_program_info paramName) const;
                void getInfo(cl_program_info paramName, size_t paramValueSize, void *paramValue) const;

                cl_build_status buildStatus(const Device& device) const
                {
                    cl_build_status ret = 0;
                    
                    getBuildInfo(CL_PROGRAM_BUILD_STATUS, device, sizeof(cl_build_status), &ret);
                    
                    return ret;
                }
                
                Epic::Core::ASCIIString buildLog(const Device& device) const
                {
                    return getBuildInfoString(CL_PROGRAM_BUILD_LOG, device);
                }
                
                EPIC_INLINE Epic::Core::ASCIIString getBuildInfoString(cl_program_build_info paramName, const Device& device) const
                {
                    size_t length = getBuildInfoSize(paramName, device);
                    char *str = new char[length];

                    getBuildInfo(paramName, device, length, str);

                    return Epic::Core::ASCIIString::wrap(str);
                }
                
                size_t getBuildInfoSize(cl_program_build_info paramName, const Device& device) const;
                void getBuildInfo(cl_program_build_info paramName, const Device& device, size_t paramValueSize, void *paramValue) const;

                bool build(const Epic::Core::Array<Device>& devices = Epic::Core::Array<Device>(),
                           const Epic::Core::ASCIIString& options = Epic::Core::ASCIIString()) const;
                
                Kernel createKernel(const Epic::Core::ASCIIString& kernelName) const;

            private:
                cl_program mProgram;
        };
    }
}

#endif	/* EPIC_OPENCL_PROGRAM_H */

