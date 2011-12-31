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

#include "Image3D.h"

namespace Epic {
namespace OpenCL {

    Image3D::Image3D()
    : mImage(0)
    {
    }
    
    Image3D::Image3D(cl_mem image)
    : mImage(image)
    {
        
    }

    Image3D::Image3D(const Image3D& other)
    : mImage(other.mImage)
    {
    }

    Image3D::~Image3D()
    {
    }
}
}
