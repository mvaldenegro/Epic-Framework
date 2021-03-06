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

#ifndef EPIC_OPENCL_DEVICE_H
#define	EPIC_OPENCL_DEVICE_H

#include <CL/opencl.h>

#include <epic.core/Array.h>
#include <epic.core/ASCIIString.h>

namespace Epic {
    namespace OpenCL {
        class Device
        {
            public:
                Device();
                Device(cl_device_id deviceID);
                Device(const Device& other);
                ~Device();
                
                Device& operator=(const Device& other);

                EPIC_INLINE cl_device_id deviceID() const
                {
                    return mDeviceID;
                }

                EPIC_INLINE Epic::Core::ASCIIString extensions() const
                {
                    return getStringInfo(CL_DEVICE_EXTENSIONS);
                }

                EPIC_INLINE Epic::Core::ASCIIString name() const
                {
                    return getStringInfo(CL_DEVICE_NAME);
                }

                EPIC_INLINE Epic::Core::ASCIIString profile() const
                {
                    return getStringInfo(CL_DEVICE_PROFILE);
                }

                EPIC_INLINE Epic::Core::ASCIIString vendor() const
                {
                    return getStringInfo(CL_DEVICE_VENDOR);
                }

                EPIC_INLINE Epic::Core::ASCIIString version() const
                {
                    return getStringInfo(CL_DEVICE_VERSION);
                }

                EPIC_INLINE Epic::Core::ASCIIString driverVersion() const
                {
                    return getStringInfo(CL_DRIVER_VERSION);
                }

                EPIC_INLINE Epic::Core::ASCIIString getStringInfo(cl_device_info paramName) const
                {
                    size_t length = getInfoSize(paramName);
                    char *str = new char[length];

                    getInfo(paramName, length, str);

                    return Epic::Core::ASCIIString::wrap(str);
                }

                size_t getInfoSize(cl_device_info paramName) const;
                void getInfo(cl_device_info paramName, size_t paramValueSize, void *paramValue) const;
                
            private:
                cl_device_id mDeviceID;
        };
    }
}

#endif	/* EPIC_OPENCL_DEVICE_H */

