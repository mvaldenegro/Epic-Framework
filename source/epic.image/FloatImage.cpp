/*
 * ImageF.cpp
 *
 *  Created on: 09-12-2011
 *      Author: mvaldenegro
 */

#include "FloatImage.h"

namespace Epic {
    namespace Image {

        FloatImage::FloatImage(size_t width, size_t height, size_t components, FloatPixelFormat format)
        : imageWidth(width), imageHeight(height), imageComponents(components),
          imageFormat(format), imagePixelData(nullptr)
        {
            imagePixelData = new float[components * width * height];
        }

        FloatImage::~FloatImage()
        {
            delete [] imagePixelData;
        }
    } /* namespace Image */
} /* namespace Epic */
