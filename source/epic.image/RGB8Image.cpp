/*
 * File:   RGB8Image.cpp
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 03:23 PM
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
