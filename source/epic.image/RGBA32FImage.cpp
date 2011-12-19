/*
 * R32FImage.cpp
 *
 *  Created on: 11-12-2011
 *      Author: mvaldenegro
 */

#include "RGBA32FImage.h"

namespace Epic {
    namespace Image {

        RGBA32FImage::RGBA32FImage(size_t width, size_t height)
        : FloatImage(width, height, 4, FloatPixelFormat::RGBA32F)
        {
        }

        RGBA32FImage::~RGBA32FImage()
        {
        }

        PixelF RGBA32FImage::pixel(size_t row, size_t column) const
        {
            const float *data = pixelData();
            size_t idx = index(row, column);

            return PixelF(data[idx], data[idx + 1], data[idx + 2], data[idx + 3]);
        }

        void RGBA32FImage::setPixel(size_t row, size_t column, const PixelF& pixel)
        {
            setPixel(row, column, pixel.r, pixel.g, pixel.b, pixel.a);
        }

        void RGBA32FImage::setPixel(size_t row, size_t column, float r, float g, float b, float a)
        {
            float *data = pixelData();
            size_t idx = index(row, column);

            data[idx    ] = r;
            data[idx + 1] = g;
            data[idx + 2] = b;
            data[idx + 3] = a;
        }


    } /* namespace Image */
} /* namespace Epic */
