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
