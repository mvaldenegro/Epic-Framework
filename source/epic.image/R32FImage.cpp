/*
 * R32FImage.cpp
 *
 *  Created on: 11-12-2011
 *      Author: mvaldenegro
 */

#include "R32FImage.h"

namespace Epic {
    namespace Image {

        R32FImage::R32FImage(size_t width, size_t height)
        : FloatImage(width, height, 1, FloatPixelFormat::R32F)
        {
        }

        R32FImage::~R32FImage()
        {
        }

        PixelF R32FImage::pixel(size_t row, size_t column) const
        {
            const float *data = pixelData();

            return PixelF(data[index(row, column)], 0.0f, 0.0f, 0.0f);
        }

        void R32FImage::setPixel(size_t row, size_t column, const PixelF& pixel)
        {
            setPixel(row, column, pixel.r);
        }

        void R32FImage::setPixel(size_t row, size_t column, float r)
        {
            float *data = pixelData();

            data[index(row, column)] = r;
        }


    } /* namespace Image */
} /* namespace Epic */
