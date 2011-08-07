/*
 * File:   RG8Image.cpp
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 04:04 PM
 */

#include "RG8Image.h"

using Epic::Core::Byte;

namespace Epic {
namespace Image {

    RG8Image::RG8Image(size_t width, size_t height)
    : Image(width, height, PixelFormat::RG8)
    {
        setPixelData(new Byte[2 * width * height]);
    }

    RG8Image::~RG8Image()
    {
        delete [] pixelData();
    }

    size_t RG8Image::bytesPerPixel() const
    {
        return 2;
    }

    Pixel RG8Image::pixel(size_t row, size_t column) const
    {
        int idx = index(row, column);
        const Byte *data = pixelData();

        return Pixel(data[idx], data[idx + 1], 255);
    }

    void RG8Image::setPixel(size_t row, size_t column, const Pixel& pixel)
    {
        int idx = index(row, column);
        Byte *data = pixelData();

        data[idx    ] = pixel.r;
        data[idx + 1] = pixel.g;
    }
}
}
