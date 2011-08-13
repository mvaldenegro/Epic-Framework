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

#include <epic.bindings.opencl/Device.h>

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
    }
}

#endif	/* HELPERS_H */

