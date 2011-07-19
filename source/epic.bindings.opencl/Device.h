/* 
 * File:   Device.h
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:49 PM
 */

#ifndef EPIC_OPENCL_DEVICE_H
#define	EPIC_OPENCL_DEVICE_H

namespace Epic {
    namespace OpenCL {
        class Device
        {
            public:
                Device(const Device& other);
                ~Device();

                static Device *selectDevices(cl_device_type deviceType);

            private:
                cl_device_id mDeviceID;
        };
    };
};

#endif	/* EPIC_OPENCL_DEVICE_H */

