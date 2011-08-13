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


