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

