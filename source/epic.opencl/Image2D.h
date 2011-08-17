/* 
 * File:   Image2D.h
 * Author: mvaldenegro
 *
 * Created on 14 de agosto de 2011, 09:31 PM
 */

#ifndef EPIC_OPENCL_IMAGE2D_H
#define	EPIC_OPENCL_IMAGE2D_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Image2D
        {
            public:
                Image2D();
                Image2D(cl_mem image);
                Image2D(const Image2D& other);
                ~Image2D();

                EPIC_INLINE cl_mem imageHandle() const
                {
                    return mImage;
                }
                
            private:
                cl_mem mImage;
        };

    }
}
#endif	/* EPIC_OPENCL_IMAGE2D_H */

