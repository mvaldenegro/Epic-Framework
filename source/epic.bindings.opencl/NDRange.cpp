/*
 * NDRange.cpp
 *
 *  Created on: 14-08-2011
 *      Author: mvaldenegro
 */

#include "NDRange.h"

namespace Epic {
    namespace OpenCL {

        NDRange::NDRange()
        : mSizes(nullptr), mDimension(0)
        {
        }

        NDRange::NDRange(size_t x)
        : mSizes(new size_t[1]), mDimension(1)
        {
            mSizes[0] = x;
        }

        NDRange::NDRange(size_t x, size_t y)
        : mSizes(new size_t[2]), mDimension(2)
        {
            mSizes[0] = x;
            mSizes[1] = y;
        }

        NDRange::NDRange(size_t x, size_t y, size_t z)
        : mSizes(new size_t[3]), mDimension(3)
        {
            mSizes[0] = x;
            mSizes[1] = y;
            mSizes[2] = z;
        }

        NDRange::~NDRange()
        {
            delete [] mSizes;
        }

    }
}
