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

#include "Event.h"
#include "OpenCLException.h"

namespace Epic {
namespace OpenCL {
    Event::Event()
    : mEvent(0)
    {
    }

    Event::Event(const Event& other)
    : mEvent(other.mEvent)
    {
    }

    Event::~Event()
    {
    }

    size_t Event::getInfoSize(cl_event_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetEventInfo(eventHandle(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Event::getInfo(cl_event_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetEventInfo(eventHandle(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }

    size_t Event::getProfilingInfoSize(cl_profiling_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetEventProfilingInfo(eventHandle(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Event::getProfilingInfo(cl_profiling_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetEventProfilingInfo(eventHandle(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }
}
}

