/* 
 * File:   Image2D.cpp
 * Author: mvaldenegro
 * 
 * Created on 14 de agosto de 2011, 09:31 PM
 */

#include "Image2D.h"

namespace Epic {
namespace OpenCL {

    Image2D::Image2D()
    : mImage(0)
    {
    }
    
    Image2D::Image2D(cl_mem image)
    : mImage(image)
    {
        
    }

    Image2D::Image2D(const Image2D& other)
    : mImage(other.mImage)
    {
    }

    Image2D::~Image2D()
    {
    }
}
}