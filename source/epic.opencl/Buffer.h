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

#ifndef EPIC_OPENCL_BUFFER_H
#define	EPIC_OPENCL_BUFFER_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        
        class Buffer
        {
            public:
                Buffer();
                Buffer(cl_mem buffer);
                Buffer(const Buffer& other);
                ~Buffer();
                
                EPIC_INLINE cl_mem bufferHandle() const
                {
                    return mBuffer;
                }
                
            private:
                cl_mem mBuffer;
        };

    }
}

#endif	/* EPIC_OPENCL_BUFFER_H */

