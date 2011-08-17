/* 
 * File:   Image3D.cpp
 * Author: mvaldenegro
 * 
 * Created on 14 de agosto de 2011, 09:31 PM
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