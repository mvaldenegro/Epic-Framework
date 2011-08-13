/*
 * File:   Program.cpp
 * Author: mvaldenegro
 *
 * Created on 12 de agosto de 2011, 12:55 PM
 */

#include "Program.h"
#include "Helpers.h"
#include "OpenCLException.h"

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

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
        
        return true;
    }
}
}


