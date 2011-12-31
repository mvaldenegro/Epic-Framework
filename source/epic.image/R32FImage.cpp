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
