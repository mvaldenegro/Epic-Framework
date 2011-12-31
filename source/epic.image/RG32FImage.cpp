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
