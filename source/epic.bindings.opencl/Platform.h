/*
 * File:   Platform.h
 * Author: mvaldenegro
 *
 * Created on 8 de agosto de 2011, 01:44 AM
 */

#ifndef EPIC_OPENCL_PLATFORM_H
#define	EPIC_OPENCL_PLATFORM_H

#include <CL/opencl.h>

#include <epic.core/Array.h>
#include <epic.core/ASCIIString.h>

#include <epic.bindings.opencl/Device.h>

namespace Epic {
    namespace OpenCL {

        class Platform
        {
            public:
                Platform();
                Platform(const Platform& platform);
                ~Platform();

                EPIC_INLINE cl_platform_id platformID() const
                {
                    return mPlatformID;
                }

                EPIC_INLINE Epic::Core::ASCIIString profile() const
                {
                    return getStringInfo(CL_PLATFORM_PROFILE);
                }

                EPIC_INLINE Epic::Core::ASCIIString version() const
                {
                    return getStringInfo(CL_PLATFORM_VERSION);
                }

                EPIC_INLINE Epic::Core::ASCIIString name() const
                {
                    return getStringInfo(CL_PLATFORM_NAME);
                }

                EPIC_INLINE Epic::Core::ASCIIString vendor() const
                {
                    return getStringInfo(CL_PLATFORM_VENDOR);
                }

                EPIC_INLINE Epic::Core::ASCIIString extensions() const
                {
                    return getStringInfo(CL_PLATFORM_EXTENSIONS);
                }

                EPIC_INLINE Epic::Core::ASCIIString getStringInfo(cl_platform_info paramName) const
                {
                    size_t length = getInfoSize(paramName);
                    char *str = new char[length];

                    getInfo(paramName, length, str);

                    return Epic::Core::ASCIIString::wrap(str);
                }

                Epic::Core::Array<Device> devices(cl_device_type deviceType) const;

                size_t getInfoSize(cl_platform_info paramName) const;
                void getInfo(cl_platform_info paramName, size_t paramValueSize, void *paramValue) const;

                static Epic::Core::Array<Platform> getPlatformIDs();

            private:
                Platform(cl_platform_id platformID);
                cl_platform_id mPlatformID;
        };
    }
}

#endif	/* EPIC_OPENCL_PLATFORM_H */

