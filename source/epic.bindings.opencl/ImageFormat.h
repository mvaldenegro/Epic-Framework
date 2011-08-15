/* 
 * File:   ImageFormat.h
 * Author: mvaldenegro
 *
 * Created on 14 de agosto de 2011, 09:53 PM
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

