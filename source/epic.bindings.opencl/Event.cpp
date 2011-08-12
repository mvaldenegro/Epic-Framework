/*
 * File:   Event.cpp
 * Author: mvaldenegro
 *
 * Created on 11 de agosto de 2011, 11:40 PM
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

