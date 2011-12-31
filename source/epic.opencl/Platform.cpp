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

#include "Platform.h"
#include "OpenCLException.h"
#include "Helpers.h"

namespace Epic {
namespace OpenCL {

    Platform::Platform()
    : mPlatformID(0)
    {
    }

    Platform::Platform(cl_platform_id platformID)
    : mPlatformID(platformID)
    {
    }

    Platform::Platform(const Platform& platform)
    : mPlatformID(platform.platformID())
    {
    }

    Platform::~Platform()
    {
    }

    size_t Platform::getInfoSize(cl_platform_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetPlatformInfo(platformID(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Platform::getInfo(cl_platform_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;

        err = clGetPlatformInfo(platformID(), paramName, paramValueSize, paramValue, nullptr);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    Epic::Core::Array<Device> Platform::devices(cl_device_type deviceType) const
    {
        Epic::Core::Array<Device> ret;
        cl_uint numDevices = 0;

        clGetDeviceIDs(platformID(), deviceType, 0, nullptr, &numDevices);

        if(numDevices > 0) {
            cl_device_id *devices = new cl_device_id[numDevices];
            int err = clGetDeviceIDs(platformID(), deviceType, numDevices, devices, nullptr);

            if(err != CL_SUCCESS) {
                throw OpenCLException(err);
            }

            ret = deviceIDToDeviceHelper(devices, numDevices);

            delete [] devices;
        }

        return ret;
    }

    Epic::Core::Array<Platform> Platform::getPlatformIDs()
    {
        Epic::Core::Array<Platform> ret;
        cl_uint numPlatforms = 0;
        clGetPlatformIDs(0, nullptr, &numPlatforms);

        if(numPlatforms > 0) {
            cl_platform_id *platforms = new cl_platform_id[numPlatforms];
            int err = clGetPlatformIDs(numPlatforms, platforms, nullptr);

            if(err != CL_SUCCESS) {
                throw OpenCLException(err);
            }

            for(cl_uint i = 0; i < numPlatforms; i++) {
                ret << Platform(platforms[i]);
            }

            delete [] platforms;
        }

        return ret;
    }

}
}
