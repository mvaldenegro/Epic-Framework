/*
 * File:   Platform.cpp
 * Author: mvaldenegro
 *
 * Created on 8 de agosto de 2011, 01:44 AM
 */

#include "Platform.h"
#include "OpenCLException.h"

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