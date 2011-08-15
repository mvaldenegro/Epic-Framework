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
            
                EPIC_INLINE ImageFormat(cl_channel_order order, cl_channel_type type)
                : mChannelOrder(order), mChannelType(type)
                {
                
                }
            
                EPIC_INLINE ImageFormat(const ImageFormat& format)
                : mChannelOrder(format.channelOrder()), mChannelType(format.channelType())
                {
                
                }
            
                EPIC_INLINE ~ImageFormat()
                {
                }
                
                EPIC_INLINE cl_channel_order channelOrder() const
                {
                    return mChannelOrder;
                }
                
                EPIC_INLINE cl_channel_type channelType() const
                {
                    return mChannelType;
                }
                
                EPIC_INLINE cl_image_format toImageFormat() const
                {
                    cl_image_format ret;
                    
                    ret.image_channel_order = channelOrder();
                    ret.image_channel_data_type = channelType();
                    
                    return ret;
                }
                
            private:
                cl_channel_order mChannelOrder;
                cl_channel_type mChannelType;
        };
    }
}

#endif	/* EPIC_OPENCL_IMAGEFORMAT_H */

