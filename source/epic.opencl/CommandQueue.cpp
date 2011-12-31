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

#include "CommandQueue.h"
#include "OpenCLException.h"
#include "Helpers.h"

using Epic::Core::Array;

namespace Epic {
namespace OpenCL {

    CommandQueue::CommandQueue()
    : mCommandQueue(0)
    {
    }

    CommandQueue::CommandQueue(cl_command_queue queue)
    : mCommandQueue(queue)
    {

    }

    CommandQueue::CommandQueue(const CommandQueue& other)
    : mCommandQueue(other.mCommandQueue)
    {
    }

    CommandQueue::~CommandQueue()
    {
    }
    
    Event CommandQueue::enqueueReadBuffer(const Buffer& buffer, bool blockingRead, size_t offset, size_t cb, void *pointer,
                                          const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueReadBuffer(queueHandle(), buffer.bufferHandle(), blockingRead, offset, cb, pointer,
                                  events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueWriteBuffer(const Buffer& buffer, bool blockingWrite, size_t offset, size_t cb, void *pointer,
                                           const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueWriteBuffer(queueHandle(), buffer.bufferHandle(), blockingWrite, offset, cb, pointer,
                                   events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    void *CommandQueue::enqueueMap(const Buffer& buffer, bool blockingMap, cl_map_flags flags, size_t offset,
                                   size_t cb, const Epic::Core::Array<Event>& eventWaitList, Event *event) const
    {
        cl_event *e = event != nullptr ? event->eventPointer() : nullptr;
        void *ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        ret = clEnqueueMapBuffer(queueHandle(), buffer.bufferHandle(), blockingMap, flags, offset, cb,
                                 events.count(), events.data(), e, &err);

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueUnmap(const Buffer& buffer, void *mappedPtr,
                                     const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueUnmapMemObject(queueHandle(), buffer.bufferHandle(), mappedPtr,
                                      events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueReadImage(const Image2D& image, bool blockingRead, const size_t origin[2], const size_t region[2],
                                         size_t rowPitch, void *pointer, const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);
        const size_t orig[3] = { origin[0], origin[1], 0};
        const size_t regn[3] = { region[0], region[1], 1};

        err = clEnqueueReadImage(queueHandle(), image.imageHandle(), blockingRead, orig, regn, rowPitch, 0, pointer,
                                 events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueReadImage(const Image3D& image, bool blockingRead, const size_t origin[3], const size_t region[3],
                                         size_t rowPitch, size_t slicePitch, void *pointer,
                                         const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueReadImage(queueHandle(), image.imageHandle(), blockingRead, origin, region, rowPitch, slicePitch,
                                 pointer, events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueWriteImage(const Image2D& image, bool blockingRead, const size_t origin[2], const size_t region[2],
                                          size_t rowPitch, void *pointer, const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);
        const size_t orig[3] = { origin[0], origin[1], 0};
        const size_t regn[3] = { region[0], region[1], 1};

        err = clEnqueueWriteImage(queueHandle(), image.imageHandle(), blockingRead, orig, regn, rowPitch, 0, pointer,
                                  events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueWriteImage(const Image3D& image, bool blockingRead, const size_t origin[3], const size_t region[3],
                                          size_t rowPitch, size_t slicePitch, void *pointer,
                                          const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueWriteImage(queueHandle(), image.imageHandle(), blockingRead, origin, region, rowPitch, slicePitch,
                                  pointer, events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    void *CommandQueue::enqueueMap(const Image2D& image, bool blockingMap, cl_map_flags flags, const size_t origin[2],
                                   const size_t region[2], size_t *rowPitch,
                                   const Epic::Core::Array<Event>& eventWaitList, Event *event) const
    {
        cl_event *e = event != nullptr ? event->eventPointer() : nullptr;
        void *ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);
        const size_t orig[3] = { origin[0], origin[1], 0};
        const size_t regn[3] = { region[0], region[1], 1};

        ret = clEnqueueMapImage(queueHandle(), image.imageHandle(), blockingMap, flags, orig, regn, rowPitch, nullptr,
                                events.count(), events.data(), e, &err);

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    void *CommandQueue::enqueueMap(const Image3D& image, bool blockingMap, cl_map_flags flags, const size_t origin[3],
                                   const size_t region[3], size_t *rowPitch, size_t *slicePitch,
                                   const Epic::Core::Array<Event>& eventWaitList, Event *event) const
    {
        cl_event *e = event != nullptr ? event->eventPointer() : nullptr;
        void *ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        ret = clEnqueueMapImage(queueHandle(), image.imageHandle(), blockingMap, flags, origin, region, rowPitch, slicePitch,
                                events.count(), events.data(), e, &err);

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueUnmap(const Image2D& image, void *mappedPtr,
                                         const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueUnmapMemObject(queueHandle(), image.imageHandle(), mappedPtr,
                                      events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }

    Event CommandQueue::enqueueUnmap(const Image3D& image, void *mappedPtr,
                                     const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
        cl_int err = 0;
        Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

        err = clEnqueueUnmapMemObject(queueHandle(), image.imageHandle(), mappedPtr,
                                      events.count(), events.data(), ret.eventPointer());

        EPIC_OPENCL_CHECK_ERROR(err)

        return ret;
    }


    Event CommandQueue::enqueueNDRangeKernel(const Kernel& kernel, const NDRange& globalWorkOffset,
                                             const NDRange& globalWorkSize, const NDRange& localWorkSize,
                                             const Epic::Core::Array<Event>& eventWaitList) const
    {
        Event ret;
    	cl_int err = 0;
    	Array<cl_event> events = eventArrayToCLEventArray(eventWaitList);

    	err = clEnqueueNDRangeKernel(queueHandle(), kernel.kernelHandle(), globalWorkSize.dimension(),
    	                             globalWorkOffset.sizes(), globalWorkSize.sizes(), localWorkSize.sizes(),
    	                             events.count(), events.data(), ret.eventPointer());

    	if(err != CL_SUCCESS) {
    	    throw OpenCLException(err);
    	}

    	return ret;
    }

    void CommandQueue::flush() const
    {
        clFlush(queueHandle());
    }
    
    void CommandQueue::finish() const
    {
        clFinish(queueHandle());
    }
}
}


