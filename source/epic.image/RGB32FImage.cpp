/*
 * R32FImage.cpp
 *
 *  Created on: 11-12-2011
 *      Author: mvaldenegro
 */

#include "RGB32FImage.h"

namespace Epic {
    namespace Image {

        RGB32FImage::RGB32FImage(size_t width, size_t height)
        : FloatImage(width, height, 3, FloatPixelFormat::RGB32F)
        {
        }

        RGB32FImage::~RGB32FImage()
        {
        }

        PixelF RGB32FImage::pixel(size_t row, size_t column) const
        {
            const float *data = pixelData();
            size_t idx = index(row, column);

            return PixelF(data[idx], data[idx + 1], data[idx + 2], 0.0f);
        }

        void RGB32FImage::setPixel(size_t row, size_t column, const PixelF& pixel)
        {
            setPixel(row, column, pixel.r, pixel.g, pixel.b);
        }

        void RGB32FImage::setPixel(size_t row, size_t column, float r, float g, float b)
        {
            float *data = pixelData();
            size_t idx = index(row, column);

            data[idx    ] = r;
            data[idx + 1] = g;
            data[idx + 2] = b;
        }


    } /* namespace Image */
} /* namespace Epic */
