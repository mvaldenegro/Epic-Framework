/*
 * File:   CLContext.cpp
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:44 PM
 */

#include "Context.h"
#include "OpenCLException.h"
#include "Helpers.h"

using Epic::Core::Array;

namespace Epic {
namespace OpenCL {

    Context::Context(const Platform& platform, cl_device_type deviceType)
    : mContext(0)
    {
        const cl_context_properties properties[] = {
            CL_CONTEXT_PLATFORM, reinterpret_cast<cl_context_properties>(platform.platformID()),
            0
        };

        cl_int err = 0;
        mContext = clCreateContextFromType(properties, deviceType,
                                           nullptr, nullptr, &err);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    Context::Context(const Platform& platform, const Epic::Core::Array<Device>& devices)
    : mContext(0)
    {
        Array<cl_device_id> deviceIDs = deviceIDHelper(devices);

        const cl_context_properties properties[] = {
            CL_CONTEXT_PLATFORM, reinterpret_cast<cl_context_properties>(platform.platformID()),
            0
        };

        cl_int err = 0;
        mContext = clCreateContext(properties, deviceIDs.count(), deviceIDs.data(),
                                   nullptr, nullptr, &err);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    Context::Context(const Context& other)
    : mContext(other.mContext)
    {
    }

    Context::~Context()
    {
    }

    Epic::Core::Array<Device> Context::devices() const
    {
        Epic::Core::Array<Device> ret;
        size_t numDevicesSize = getInfoSize(CL_CONTEXT_DEVICES);
        size_t numDevices =  numDevicesSize / sizeof(cl_device_id);

        if(numDevices > 0) {
            cl_device_id *devs = new cl_device_id[numDevices];

            getInfo(CL_CONTEXT_DEVICES, numDevicesSize, devs);

            ret = deviceIDToDeviceHelper(devs, numDevices);

            delete [] devs;
        }

        return ret;
    }

    size_t Context::getInfoSize(cl_context_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetContextInfo(contextHandle(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Context::getInfo(cl_context_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetContextInfo(contextHandle(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    CommandQueue Context::createCommandQueue(const Device& device, cl_command_queue_properties properties)
    {
        cl_command_queue queue;
        cl_int err = 0;

        queue = clCreateCommandQueue(contextHandle(), device.deviceID(), properties, &err);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return CommandQueue(queue);
    }

    Program Context::createProgram(const Epic::Core::ASCIIString& sourceCode)
    {
        cl_int err = 0;
        const char *source = sourceCode.data();

        cl_program program = clCreateProgramWithSource(contextHandle(), 1, &source, nullptr, &err);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return Program(program);
    }
}
}