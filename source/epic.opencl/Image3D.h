/* 
 * File:   Image3D.h
 * Author: mvaldenegro
 *
 * Created on 14 de agosto de 2011, 09:31 PM
 */

#ifndef EPIC_OPENCL_IMAGE3D_H
#define	EPIC_OPENCL_IMAGE3D_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Image3D
        {
            public:
                Image3D();
                Image3D(cl_mem image);
                Image3D(const Image3D& other);
                ~Image3D();

                EPIC_INLINE cl_mem imageHandle() const
                {
                    return mImage;
                }
                
            private:
                cl_mem mImage;
        };

    }
}
#endif	/* EPIC_OPENCL_IMAGE3D_H */

