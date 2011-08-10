/*
 * File:   Platform.cpp
 * Author: mvaldenegro
 *
 * Created on 8 de agosto de 2011, 01:44 AM
 */

#include "Platform.h"

namespace Epic {
namespace OpenCL {
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

    Epic::Core::Array<Platform> Platform::getPlatformIDs()
    {
        Epic::Core::Array<Platform> ret;
        cl_uint numPlatforms = 0;
        clGetPlatformIDs(0, nullptr, &numPlatforms);

        if(numPlatforms > 0) {
            cl_platform_id *platforms = new cl_platform_id[numPlatforms];
            clGetPlatformIDs(numPlatforms, platforms, nullptr);

            for(cl_uint i = 0; i < numPlatforms; i++) {
                ret << Platform(platforms[i]);
            }
        }

        return ret;
    }

}
}