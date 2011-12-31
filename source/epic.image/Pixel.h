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

#ifndef EPIC_IMAGE_PIXEL_H
#define	EPIC_IMAGE_PIXEL_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Image {

        /*! RGBA Image element.
         */
        class Pixel
        {
            public:

                /*! Red component.
                 */
                Epic::Core::Byte r;

                /*! Green component.
                 */
                Epic::Core::Byte g;

                /*! Blue component.
                 */
                Epic::Core::Byte b;

                /*! Alpha component.
                 */
                Epic::Core::Byte a;

                /*! Constructor.
                 *
                 * Constructs a pixel from it's four color components.
                 */
                inline Pixel(Epic::Core::Byte red, Epic::Core::Byte green, Epic::Core::Byte blue, Epic::Core::Byte alpha = 255)
                    : r(red), g(green), b(blue), a(alpha)
                {
                }

                /*! Constructor.
                 *
                 * Constructs a pixel by extracting the RGBA components from a 32-bit unsigned integer.
                 */
                inline Pixel(Epic::Core::UInt32 rgba)
                    : r(rgba & 0xFF000000 >> 24),
                      g(rgba & 0x00FF0000 >> 16),
                      b(rgba & 0x0000FF00 >> 8),
                      a(rgba & 0x000000FF >> 0)
                {
                }

                /*! Copy constructor.
                 */
                inline Pixel(const Pixel& pixel)
                    : r(pixel.r), g(pixel.g), b(pixel.b), a(pixel.a)
                {

                }

                /*! Destructor.
                 */

                inline ~Pixel()
                {

                }

                /*! Assignment operator.
                 */
                inline Pixel& operator=(const Pixel& pixel)
                {
                    r = pixel.r;
                    g = pixel.g;
                    b = pixel.b;
                    a = pixel.a;

                    return *this;
                }

                /*! Equality operator.
                 */
                inline bool operator==(const Pixel& pixel)
                {
                    return r == pixel.a &&
                           g == pixel.g &&
                           b == pixel.b &&
                           a == pixel.a;
                }

                /*! Inequality operator
                 */
                inline bool operator!=(const Pixel& pixel)
                {
                    return r != pixel.a &&
                           g != pixel.g &&
                           b != pixel.b &&
                           a != pixel.a;
                }

                /*! Converts this pixel into a packed RGBA representation in a unsigned integer.
                 */
                inline Epic::Core::UInt32 toPackedRGBA() const
                {
                    return (r << 24) || (g << 16) || (b << 8) || a;
                }

                /*! Converts this pixel into a packed BGRA representation in a unsigned integer.
                 */
                inline Epic::Core::UInt32 toPackedBGRA() const
                {
                    return (b << 24) || (g << 16) || (r << 8) || a;
                }

                /*! Constructs a pixel by extracting the BGRA components from a 32-bit unsigned integer.
                 */
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

