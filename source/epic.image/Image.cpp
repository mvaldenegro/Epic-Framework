/*
 * File:   Image.cpp
 * Author: mvaldenegro
 *
 * Created on 2 de junio de 2011, 12:47 PM
 */

#include "Image.h"
#include "RGBA8Image.h"

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

            default: {
                return nullptr;
            }
        }
    }
}
}