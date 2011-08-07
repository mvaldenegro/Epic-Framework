/*
 * File:   R8Image.cpp
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 04:17 PM
 */

#include "R8Image.h"

using Epic::Core::Byte;

namespace Epic {
namespace Image {

    R8Image::R8Image(size_t width, size_t height)
    : Image(width, height, PixelFormat::R8)
    {
        setPixelData(new Byte[1 * width * height]);
    }

    R8Image::~R8Image()
    {
        delete [] pixelData();
    }

    size_t R8Image::bytesPerPixel() const
    {
        return 1;
    }

    Pixel R8Image::pixel(size_t row, size_t column) const
    {
        int idx = index(row, column);
        const Byte *data = pixelData();

        return Pixel(data[idx], 255, 255);
    }

    void R8Image::setPixel(size_t row, size_t column, const Pixel& pixel)
    {
        int idx = index(row, column);
        Byte *data = pixelData();

        data[idx] = pixel.r;
    }
}
}
