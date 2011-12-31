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

#ifndef EPIC_IMAGE_PIXEL_FLOAT_H
#define EPIC_IMAGE_PIXEL_FLOAT_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Image {

        /*! Floating point RGBA image element.
         */
        class PixelF
        {
            public:

                /*! Red component.
                 */
                float r;

                /*! Green component.
                 */
                float g;

                /*! Blue component.
                 */
                float b;

                /*! Alpha component.
                 */
                float a;

                /*! Constructor.
                 *
                 * Constructs a pixel from it's four color components.
                 */
                inline PixelF(float red, float green, float blue, float alpha = 1.0f)
                    : r(red), g(green), b(blue), a(alpha)
                {
                }

                /*! Copy constructor.
                 */
                inline PixelF(const PixelF& pixel)
                    : r(pixel.r), g(pixel.g), b(pixel.b), a(pixel.a)
                {

                }

                /*! Destructor.
                 */

                inline ~PixelF()
                {
                }

                /*! Assignment operator.
                 */
                inline PixelF& operator=(const PixelF& pixel)
                {
                    r = pixel.r;
                    g = pixel.g;
                    b = pixel.b;
                    a = pixel.a;

                    return *this;
                }

                /*! Equality operator.
                 */
                inline bool operator==(const PixelF& pixel)
                {
                    return r == pixel.a &&
                           g == pixel.g &&
                           b == pixel.b &&
                           a == pixel.a;
                }

                /*! Inequality operator
                 */
                inline bool operator!=(const PixelF& pixel)
                {
                    return r != pixel.a &&
                           g != pixel.g &&
                           b != pixel.b &&
                           a != pixel.a;
                }

        } EPIC_PACKED;
    }
}

#endif  /* EPIC_IMAGE_PIXEL_FLOAT_H */

