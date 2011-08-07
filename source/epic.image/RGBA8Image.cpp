/*
 * File:   RGBA8Image.cpp
 * Author: mvaldenegro
 *
 * Created on 28 de julio de 2011, 07:49 PM
 */

#include "RGBA8Image.h"

using Epic::Core::Byte;

namespace Epic {
namespace Image {

    RGBA8Image::RGBA8Image(size_t width, size_t height)
    : Image(width, height, PixelFormat::RGBA8)
    {
        setPixelData(new Byte[4 * width * height]);
    }

    RGBA8Image::~RGBA8Image()
    {
        delete [] pixelData();
    }

    size_t RGBA8Image::bytesPerPixel() const
    {
        return 4;
    }

    Pixel RGBA8Image::pixel(size_t row, size_t column) const
    {
        int idx = index(row, column);
        const Byte *data = pixelData();

        return Pixel(data[idx], data[idx + 1], data[idx + 2], data[idx + 3]);
    }

    void RGBA8Image::setPixel(size_t row, size_t column, const Pixel& pixel)
    {
        int idx = index(row, column);
        Byte *data = pixelData();

        data[idx    ] = pixel.r;
        data[idx + 1] = pixel.g;
        data[idx + 2] = pixel.b;
        data[idx + 3] = pixel.a;
    }
}
}
