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

#ifndef EPIC_OPENCL_EVENT_H
#define	EPIC_OPENCL_EVENT_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Event
        {
            public:
                Event();
                Event(const Event& other);
                ~Event();

                EPIC_INLINE cl_event eventHandle() const
                {
                    return mEvent;
                }

                EPIC_INLINE cl_event *eventPointer()
                {
                    return &mEvent;
                }

                size_t getInfoSize(cl_event_info paramName) const;
                void getInfo(cl_event_info paramName, size_t paramValueSize, void *paramValue) const;

                EPIC_INLINE cl_ulong commandQueued() const
                {
                    return getProfilingInfoULong(CL_PROFILING_COMMAND_QUEUED);
                }

                EPIC_INLINE cl_ulong commandSubmit() const
                {
                    return getProfilingInfoULong(CL_PROFILING_COMMAND_SUBMIT);
                }

                EPIC_INLINE cl_ulong commandStart() const
                {
                    return getProfilingInfoULong(CL_PROFILING_COMMAND_START);
                }

                EPIC_INLINE cl_ulong commandEnd() const
                {
                    return getProfilingInfoULong(CL_PROFILING_COMMAND_END);
                }

                EPIC_INLINE cl_ulong getProfilingInfoULong(cl_profiling_info paramName) const
                {
                    cl_ulong ret = 0;

                    getProfilingInfo(paramName, sizeof(cl_ulong), &ret);

                    return ret;
                }

                size_t getProfilingInfoSize(cl_profiling_info paramName) const;
                void getProfilingInfo(cl_profiling_info paramName, size_t paramValueSize, void *paramValue) const;



            private:
                cl_event mEvent;

        };

    }
}

#endif	/* EPIC_OPENCL_EVENT_H */

