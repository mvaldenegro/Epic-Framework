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

    Epic::Core::Array<Device> Device::getDevices(const Platform& platform, cl_device_type deviceType)
    {
        Epic::Core::Array<Device> ret;
        cl_uint numDevices = 0;

        clGetDeviceIDs(platform.platformID(), deviceType, 0, nullptr, &numDevices);

        if(numDevices > 0) {
            cl_device_id *devices = new cl_device_id[numDevices];
            int err = clGetDeviceIDs(platform.platformID(), deviceType, numDevices, devices, nullptr);

            if(err != CL_SUCCESS) {
                throw OpenCLException(err);
            }

            for(cl_uint i = 0; i < numDevices; i++) {
                ret << Device(devices[i]);
            }

            delete [] devices;
        }

        return ret;
    }

    Device Device::wrap(cl_device_id deviceID)
    {
        return Device(deviceID);
    }
}
}