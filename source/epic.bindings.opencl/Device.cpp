/*
 * File:   Device.cpp
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:49 PM
 */

#include "Device.h"

namespace Epic {
namespace OpenCL {

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

    Epic::Core::Array<Device> getDevices(const Platform& platform, cl_device_type deviceType)
    {
        Epic::Core::Array<Device> ret;
        cl_uint numDevices = 0;

        clGetDeviceIDs(platform.platformID(), deviceType, 0, nullptr, &numDevices);

        if(numDevices > 0) {
            cl_device_id *devices = new cl_device_id[numDevices];
            clGetDeviceIDs(platform.platformID(), deviceType, numDevices, devices, nullptr);

            for(cl_uint i = 0; i < numDevices; i++) {
                ret << Device(devices[i]);
            }
        }

        return ret;
    }
}
}