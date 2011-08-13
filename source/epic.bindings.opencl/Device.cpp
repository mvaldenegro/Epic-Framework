/*
 * File:   Device.cpp
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:49 PM
 */

#include "Device.h"
#include "OpenCLException.h"


namespace Epic {
namespace OpenCL {

    Device::Device()
    : mDeviceID(0)
    {
    }

    Device::Device(cl_device_id deviceID)
    : mDeviceID(deviceID)
    {
    }

    Device::Device(const Device& device)
    : mDeviceID(device.deviceID())
    {
    }

    Device::~Device() {
    }

    size_t Device::getInfoSize(cl_device_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetDeviceInfo(deviceID(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Device::getInfo(cl_device_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;

        err = clGetDeviceInfo(deviceID(), paramName, paramValueSize, paramValue, nullptr);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }
}
}