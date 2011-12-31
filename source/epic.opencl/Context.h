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

#ifndef EPIC_OPENCL_CLCONTEXT_H
#define	EPIC_OPENCL_CLCONTEXT_H

#include <epic.core/Array.h>

#include <epic.opencl/Device.h>
#include <epic.opencl/CommandQueue.h>
#include <epic.opencl/Program.h>
#include <epic.opencl/Platform.h>
#include <epic.opencl/Buffer.h>
#include <epic.opencl/Image2D.h>
#include <epic.opencl/Image3D.h>
#include <epic.opencl/ImageFormat.h>
#include <epic.opencl/Sampler.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Context
        {
            public:
                Context(const Platform& platform, cl_device_type deviceType);
                Context(const Platform& platform, const Epic::Core::Array<Device>& devices);
                Context(const Context& other);
                ~Context();

                inline cl_context contextHandle() const
                {
                    return mContext;
                }

                Epic::Core::Array<Device> devices() const;

                size_t getInfoSize(cl_context_info paramName) const;
                void getInfo(cl_context_info paramName, size_t paramValueSize, void *paramValue) const;

                Epic::Core::Array<ImageFormat> supportedImageFormats(cl_mem_flags flags, cl_mem_object_type type) const;

                CommandQueue createCommandQueue(const Device& device, cl_command_queue_properties properties = 0) const;
                
                Buffer createBuffer(cl_mem_flags flags, size_t size, void *hostPointer = nullptr) const;
                
                Image2D createImage2D(cl_mem_flags flags, const ImageFormat& format,
                                      size_t width, size_t height, size_t rowPitch = 0,
                                      void *hostPointer = nullptr);
                
                Image3D createImage3D(cl_mem_flags flags, const ImageFormat& format,
                                      size_t width, size_t height, size_t depth,
                                      size_t rowPitch = 0, size_t slicePitch = 0,
                                      void *hostPointer = nullptr);
                
                Sampler createSampler(bool normalizedCoords, cl_addressing_mode addrMode, cl_filter_mode filter);
                
                Program createProgram(const Epic::Core::ASCIIString& sourceCode) const;

            private:
                cl_context mContext;
        };
    }
}

#endif	/* EPIC_OPENCL_CLCONTEXT_H */

