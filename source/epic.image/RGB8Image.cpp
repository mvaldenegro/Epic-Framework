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

#include "RGB8Image.h"

using Epic::Core::Byte;

namespace Epic {
namespace Image {

    RGB8Image::RGB8Image(size_t width, size_t height)
    : Image(width, height, PixelFormat::RGB8)
    {
        setPixelData(new Byte[3 * width * height]);
    }

    RGB8Image::~RGB8Image()
    {
        delete [] pixelData();
    }

    size_t RGB8Image::bytesPerPixel() const
    {
        return 3;
    }

    Pixel RGB8Image::pixel(size_t row, size_t column) const
    {
        int idx = index(row, column);
        const Byte *data = pixelData();

        return Pixel(data[idx], data[idx + 1], data[idx + 2]);
    }

    void RGB8Image::setPixel(size_t row, size_t column, const Pixel& pixel)
    {
        int idx = index(row, column);
        Byte *data = pixelData();

        data[idx    ] = pixel.r;
        data[idx + 1] = pixel.g;
        data[idx + 2] = pixel.b;
    }
}
}
