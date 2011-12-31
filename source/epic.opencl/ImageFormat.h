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

#ifndef EPIC_OPENCL_IMAGEFORMAT_H
#define	EPIC_OPENCL_IMAGEFORMAT_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class ImageFormat
        {
            public:

                EPIC_INLINE ImageFormat()
                : mImageFormat(cl_image_format())
                {
                }
            
                EPIC_INLINE ImageFormat(cl_image_format format)
                : mImageFormat(format)
                {
                }

                EPIC_INLINE ImageFormat(cl_channel_order order, cl_channel_type type)
                : mImageFormat(cl_image_format())
                {
                    mImageFormat.image_channel_order = order;
                    mImageFormat.image_channel_data_type = type;
                }
            
                EPIC_INLINE ImageFormat(const ImageFormat& other)
                : mImageFormat(other.format())
                {
                }
            
                EPIC_INLINE ~ImageFormat()
                {
                }
                
                EPIC_INLINE cl_channel_order channelOrder() const
                {
                    return mImageFormat.image_channel_order;
                }
                
                EPIC_INLINE cl_channel_type channelType() const
                {
                    return mImageFormat.image_channel_data_type;
                }
                
                EPIC_INLINE cl_image_format format() const
                {
                    return mImageFormat;
                }
                
            private:
                cl_image_format mImageFormat;
        };
    }
}

#endif	/* EPIC_OPENCL_IMAGEFORMAT_H */

