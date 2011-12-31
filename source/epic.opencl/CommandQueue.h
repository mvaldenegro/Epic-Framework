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

#ifndef EPIC_OPENCL_COMMANDQUEUE_H
#define	EPIC_OPENCL_COMMANDQUEUE_H

#include <epic.core/Core.h>
#include <epic.core/Array.h>

#include <CL/opencl.h>

#include <epic.opencl/Buffer.h>
#include <epic.opencl/Kernel.h>
#include <epic.opencl/NDRange.h>
#include <epic.opencl/Event.h>
#include <epic.opencl/Image2D.h>
#include <epic.opencl/Image3D.h>

namespace Epic {
    namespace OpenCL {
        class CommandQueue {
            public:
                CommandQueue();
                CommandQueue(cl_command_queue queue);
                CommandQueue(const CommandQueue& other);
                ~CommandQueue();

                EPIC_INLINE cl_command_queue queueHandle() const
                {
                    return mCommandQueue;
                }

                Event enqueueReadBuffer(const Buffer& buffer, bool blockingRead, size_t offset, size_t cb, void *pointer,
                                        const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueWriteBuffer(const Buffer& buffer, bool blockingWrite, size_t offset, size_t cb, void *pointer,
                                         const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                void *enqueueMap(const Buffer& buffer, bool blockingMap, cl_map_flags flags, size_t offset, size_t cb,
                                 const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>(),
                                 Event *event = nullptr) const;

                Event enqueueUnmap(const Buffer& buffer, void *mappedPtr,
                                   const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueReadImage(const Image2D& image, bool blockingRead, const size_t origin[2],
                                       const size_t region[2], size_t rowPitch, void *pointer,
                                       const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueReadImage(const Image3D& image, bool blockingRead, const size_t origin[3],
                                       const size_t region[3], size_t rowPitch, size_t slicePitch, void *pointer,
                                       const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueWriteImage(const Image2D& image, bool blockingRead, const size_t origin[2],
                                        const size_t region[2], size_t rowPitch, void *pointer,
                                        const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueWriteImage(const Image3D& image, bool blockingRead, const size_t origin[3],
                                        const size_t region[3], size_t rowPitch, size_t slicePitch, void *pointer,
                                        const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                void *enqueueMap(const Image2D& image, bool blockingMap, cl_map_flags flags, const size_t origin[2],
                                 const size_t region[2], size_t *rowPitch,
                                 const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>(),
                                 Event *event = nullptr) const;

                void *enqueueMap(const Image3D& image, bool blockingMap, cl_map_flags flags, const size_t origin[3],
                                 const size_t region[3], size_t *rowPitch, size_t *slicePitch,
                                 const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>(),
                                 Event *event = nullptr) const;

                Event enqueueUnmap(const Image2D& image, void *mappedPtr,
                                   const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueUnmap(const Image3D& image, void *mappedPtr,
                                   const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueNDRangeKernel(const Kernel& kernel, const NDRange& globalWorkOffset,
                                           const NDRange& globalWorkSize, const NDRange& localWorkSize,
                                           const Epic::Core::Array<Event>& eventWaitList = Epic::Core::Array<Event>()) const;

                Event enqueueMarker() const;
                void enqueueWaitForEvents(const Epic::Core::Array<Event>& events) const;
                void enqueueBarrier() const;

                void flush() const;
                void finish() const;

            private:
                cl_command_queue mCommandQueue;

        };

    }
}


#endif	/* EPIC_OPENCL_COMMANDQUEUE_H */

