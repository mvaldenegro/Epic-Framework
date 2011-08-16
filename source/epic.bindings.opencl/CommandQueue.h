/*
 * File:   CommandQueue.h
 * Author: mvaldenegro
 *
 * Created on 11 de agosto de 2011, 11:34 PM
 */

#ifndef EPIC_OPENCL_COMMANDQUEUE_H
#define	EPIC_OPENCL_COMMANDQUEUE_H

#include <epic.core/Core.h>
#include <epic.core/Array.h>

#include <CL/opencl.h>

#include <epic.bindings.opencl/Buffer.h>
#include <epic.bindings.opencl/Kernel.h>
#include <epic.bindings.opencl/NDRange.h>
#include <epic.bindings.opencl/Event.h>
#include <epic.bindings.opencl/Image2D.h>
#include <epic.bindings.opencl/Image3D.h>

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

