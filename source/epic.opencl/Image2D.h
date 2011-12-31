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

