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

#include "Image.h"
#include "RGBA8Image.h"
#include "RGB8Image.h"
#include "RG8Image.h"
#include "R8Image.h"

namespace Epic {
namespace Image {

    Image::Image(size_t width, size_t height, PixelFormat format)
    : imageWidth(width), imageHeight(height), imageFormat(format)
    {
    }

    Image::~Image()
    {
    }

    Image *Image::converted(PixelFormat format) const
    {
        Image *ret = Image::createFromFormat(width(), height(), format);

        for(size_t row = 0; row < ret->height(); row++) {
            for(size_t column = 0; column < ret->width(); column++) {
                ret->setPixel(row, column, pixel(row, column));
            }
        }

        return ret;
    }

    Image* Image::createFromFormat(size_t width, size_t height, PixelFormat format)
    {
        switch(format) {
            case PixelFormat::RGBA8: {
                return new RGBA8Image(width, height);
            }

            case PixelFormat::RGB8: {
                return new RGB8Image(width, height);
            }

            case PixelFormat::RG8: {
                return new RG8Image(width, height);
            }

            case PixelFormat::R8: {
                return new R8Image(width, height);
            }

            default: {
                return nullptr;
            }
        }
    }
}
}
