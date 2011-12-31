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

#include "Program.h"
#include "Helpers.h"
#include "OpenCLException.h"

#include <iostream>

using std::cout;
using std::endl;

using Epic::Core::Array;

namespace Epic {
namespace OpenCL {

    Program::Program()
    : mProgram(0)
    {
    }

    Program::Program(cl_program program)
    : mProgram(program)
    {
    }

    Program::Program(const Program& other)
    : mProgram(other.mProgram)
    {
    }

    Program::~Program()
    {
    }

    Epic::Core::Array<Device> Program::devices() const
    {
        Epic::Core::Array<Device> ret;
        size_t numDevices = numberOfDevices();

        if(numDevices > 0) {
            cl_device_id *devs = new cl_device_id[numDevices];

            getInfo(CL_PROGRAM_DEVICES, sizeof(cl_device_id) * numDevices, devs);

            ret = deviceIDToDeviceHelper(devs, numDevices);

            delete [] devs;
        }

        return ret;
    }

    size_t Program::getInfoSize(cl_program_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetProgramInfo(programHandle(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Program::getInfo(cl_program_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetProgramInfo(programHandle(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    size_t Program::getBuildInfoSize(cl_program_build_info paramName, const Device& device) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetProgramBuildInfo(programHandle(), device.deviceID(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Program::getBuildInfo(cl_program_build_info paramName, const Device& device, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetProgramBuildInfo(programHandle(), device.deviceID(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    bool Program::build(const Epic::Core::Array<Device>& devices,
                        const Epic::Core::ASCIIString& options) const
    {
        Array<cl_device_id> deviceArray;
        size_t numDevices = 0;

        if(devices.isEmpty()) {
            numDevices = devices.count();
            deviceArray = deviceIDHelper(devices);
        }

        cl_int err = clBuildProgram(programHandle(), numDevices, deviceArray.data(), options.data(), nullptr, nullptr);
        
        /* Skip CL_BUILD_PROGRAM_FAILURE error, will be handled later in this code. */
        if((err != CL_BUILD_PROGRAM_FAILURE) && (err != CL_SUCCESS)) {
            throw OpenCLException(err);
        }
        
        Epic::Core::Array<Device> devs;
        bool ret = true;
        
        if(devices.isEmpty()) {
            devs = this->devices();
        } else {
            devs = devices;
        }
                
        for(size_t i = 0; i < devs.count(); i++) {
            cl_build_status status = buildStatus(devs[i]);
            
            cout << "Build log for device " << devs[i].deviceID() << endl;
            cout << buildLog(devs[i]) << endl;
            
            while(status == CL_BUILD_IN_PROGRESS) {
                status = buildStatus(devs[i]);
            }
            
            if(status == CL_BUILD_SUCCESS) {
                cout << "Program compilation successful" << endl;
            } else {
                cout << "Program compilation failed" << endl;
            }
            
            ret &= (status == CL_BUILD_SUCCESS);
        }
        
        return ret;
    }
    
    Kernel Program::createKernel(const Epic::Core::ASCIIString& kernelName) const
    {
        cl_int err = 0;
        cl_kernel kernel = clCreateKernel(programHandle(), kernelName.data(), &err);
        
        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
        
        return Kernel(kernel);
    }
}
}


