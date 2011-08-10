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

namespace Epic {
    namespace OpenCL {
        class Device
        {
            public:
                Device(const Device& other);
                ~Device();

                EPIC_INLINE cl_device_id deviceID() const
                {
                    return mDeviceID;
                }

                static Epic::Core::Array<Device> getDevices(const Platform& platform, cl_device_type deviceType);

            private:
                Device(cl_device_id deviceID);
                cl_device_id mDeviceID;
        };
    };
};

#endif	/* EPIC_OPENCL_DEVICE_H */

