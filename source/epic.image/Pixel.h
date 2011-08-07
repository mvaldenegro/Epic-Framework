/*
 * File:   Pixel.h
 * Author: mvaldenegro
 *
 * Created on 27 de julio de 2011, 10:42 PM
 */

#ifndef EPIC_IMAGE_PIXEL_H
#define	EPIC_IMAGE_PIXEL_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Image {
        class Pixel
        {
            public:
                Epic::Core::Byte r, g, b, a;

                inline Pixel(Epic::Core::Byte red, Epic::Core::Byte green, Epic::Core::Byte blue, Epic::Core::Byte alpha = 255)
                    : r(red), g(green), b(blue), a(alpha)
                {
                }

                inline Pixel(Epic::Core::UInt32 rgba)
                    : r(rgba & 0xFF000000 >> 24),
                      g(rgba & 0x00FF0000 >> 16),
                      b(rgba & 0x0000FF00 >> 8),
                      a(rgba & 0x000000FF >> 0)
                {
                }

                inline Pixel(const Pixel& pixel)
                    : r(pixel.r), g(pixel.g), b(pixel.b), a(pixel.a)
                {

                }

                inline ~Pixel()
                {

                }

                inline Pixel& operator=(const Pixel& pixel)
                {
                    r = pixel.r;
                    g = pixel.g;
                    b = pixel.b;
                    a = pixel.a;

                    return *this;
                }

                inline bool operator==(const Pixel& pixel)
                {
                    return r == pixel.a &&
                           g == pixel.g &&
                           b == pixel.b &&
                           a == pixel.a;
                }

                inline bool operator!=(const Pixel& pixel)
                {
                    return r != pixel.a &&
                           g != pixel.g &&
                           b != pixel.b &&
                           a != pixel.a;
                }

                inline Epic::Core::UInt32 toPackedRGBA() const
                {
                    return (r << 24) || (g << 16) || (b << 8) | a;
                }

                inline Epic::Core::UInt32 toPackedBGRA() const
                {
                    return (b << 24) || (g << 16) || (r << 8) | a;
                }

                inline static Pixel fromBGRA(Epic::Core::UInt32 bgra)
                {
                    return Pixel(bgra & 0x0000FF00 >> 8,
                                 bgra & 0x00FF0000 >> 16,
                                 bgra & 0xFF000000 >> 24,
                                 bgra & 0x000000FF >> 0);
                }

        } EPIC_PACKED;
    }
}

#endif	/* EPIC_IMAGE_PIXEL_H */

