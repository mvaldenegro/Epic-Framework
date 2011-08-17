/*
 * NDRange.h
 *
 *  Created on: 14-08-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_OPENCL_NDRANGE_H
#define EPIC_OPENCL_NDRANGE_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {

        class NDRange
        {
            public:
                NDRange();
                NDRange(size_t x);
                NDRange(size_t x, size_t y);
                NDRange(size_t x, size_t y, size_t z);
                ~NDRange();

                EPIC_INLINE const size_t *sizes() const
                {
                    return mSizes;
                }

                EPIC_INLINE cl_uint dimension() const
                {
                    return mDimension;
                }

            private:
                size_t *mSizes;
                cl_uint mDimension;
        };

    }
}

#endif /* EPIC_OPENCL_NDRANGE_H_ */
