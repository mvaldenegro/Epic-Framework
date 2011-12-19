/*
 * R32FImage.cpp
 *
 *  Created on: 11-12-2011
 *      Author: mvaldenegro
 */

#include "RG32FImage.h"

namespace Epic {
    namespace Image {

        RG32FImage::RG32FImage(size_t width, size_t height)
        : FloatImage(width, height, 2, FloatPixelFormat::RG32F)
        {
        }

        RG32FImage::~RG32FImage()
        {
        }

        PixelF RG32FImage::pixel(size_t row, size_t column) const
        {
            const float *data = pixelData();
            size_t idx = index(row, column);

            return PixelF(data[idx], data[idx + 1], 0.0f, 0.0f);
        }

        void RG32FImage::setPixel(size_t row, size_t column, const PixelF& pixel)
        {
            setPixel(row, column, pixel.r, pixel.g);
        }

        void RG32FImage::setPixel(size_t row, size_t column, float r, float g)
        {
            float *data = pixelData();
            size_t idx = index(row, column);

            data[idx    ] = r;
            data[idx + 1] = g;
        }


    } /* namespace Image */
} /* namespace Epic */
