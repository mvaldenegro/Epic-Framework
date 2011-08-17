/*
 * File:   Helpers.h
 * Author: mvaldenegro
 *
 * Created on 12 de agosto de 2011, 02:12 PM
 */

#ifndef HELPERS_H
#define	HELPERS_H

#include <CL/opencl.h>

#include <epic.core/Array.h>

#include <epic.opencl/Device.h>
#include <epic.opencl/Event.h>

namespace Epic {
    namespace OpenCL {
        static inline Epic::Core::Array<cl_device_id> deviceIDHelper(const Epic::Core::Array<Epic::OpenCL::Device>& devices)
        {
            Epic::Core::Array<cl_device_id> ret;
            ret.reserve(devices.count());

            for(size_t i = 0; i < devices.count(); i++) {
                ret << devices[i].deviceID();
            }

            return ret;
        }

        static inline Epic::Core::Array<Device> deviceIDToDeviceHelper(const cl_device_id* devs, size_t length)
        {
            Epic::Core::Array<Device> ret;

            for(size_t i = 0; i < length; i++) {
                ret << Device(devs[i]);
            }

            return ret;
        }

        static inline Epic::Core::Array<cl_event> eventArrayToCLEventArray(const Epic::Core::Array<Event>& events)
        {
            Epic::Core::Array<cl_event> ret;

            for(size_t i = 0; i < events.count(); i++) {
                ret << events[i].eventHandle();
            }

            return ret;
        }
    }
}

#endif	/* HELPERS_H */

