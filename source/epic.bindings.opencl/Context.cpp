/*
 * File:   CLContext.cpp
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:44 PM
 */

#include "Context.h"
#include "OpenCLException.h"

using Epic::Core::Array;

static inline Array<cl_device_id> deviceIDHelper(const Array<Epic::OpenCL::Device>& devices)
{
    Array<cl_device_id> ret;
    ret.reserve(devices.count());

    for(size_t i = 0; i < devices.count(); i++) {
        ret << devices[i].deviceID();
    }

    return ret;
}

namespace Epic {
namespace OpenCL {

    Context::Context(const Platform& platform, cl_device_type deviceType)
    : mContext(0)
    {
        const cl_context_properties properties[] = {
            CL_CONTEXT_PLATFORM, (cl_context_properties) platform.platformID()
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
        Array<cl_device_id> deviceIDs =deviceIDHelper(devices);

        const cl_context_properties properties[] = {
            CL_CONTEXT_PLATFORM, (cl_context_properties) platform.platformID()
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
        size_t numDevices = getInfoSize(CL_CONTEXT_DEVICES);

        if(numDevices > 0) {
            cl_device_id *devs = new cl_device_id[numDevices];

            getInfo(CL_CONTEXT_DEVICES, numDevices, devs);

            for(size_t i = 0; i < numDevices; i++) {

                ret << Device::wrap(devs[i]);
            }

            delete [] devs;
        }

        return ret;
    }

    size_t Context::getInfoSize(cl_context_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetContextInfo(clContext(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Context::getInfo(cl_context_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetContextInfo(clContext(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }
}
}