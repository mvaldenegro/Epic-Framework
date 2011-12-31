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

#ifndef EPIC_OPENCL_PLATFORM_H
#define	EPIC_OPENCL_PLATFORM_H

#include <CL/opencl.h>

#include <epic.core/Array.h>
#include <epic.core/ASCIIString.h>

#include <epic.opencl/Device.h>

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

