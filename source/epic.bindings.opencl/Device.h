/*
 * File:   Device.h
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:49 PM
 */

#ifndef EPIC_OPENCL_DEVICE_H
#define	EPIC_OPENCL_DEVICE_H

#include <CL/cl.h>
#include <epic.core/Array.h>

#include <epic.bindings.opencl/Platform.h>

namespace Epic {
    namespace OpenCL {
        class Device
        {
            public:
                Device();
                Device(const Device& other);
                ~Device();

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

                static Epic::Core::Array<Device> getDevices(const Platform& platform, cl_device_type deviceType);
                static Device wrap(cl_device_id deviceID);

            private:
                Device(cl_device_id deviceID);
                cl_device_id mDeviceID;
        };
    }
}

#endif	/* EPIC_OPENCL_DEVICE_H */

