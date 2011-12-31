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

#ifndef EPIC_IMAGE_FLOAT_PIXELFORMAT_H
#define EPIC_IMAGE_FLOAT_PIXELFORMAT_H

namespace Epic {
    namespace Image {

        /*! Pixel format for images.
         */

        class FloatPixelFormat
        {
            public:
                enum Type
                {
                    R32F,     /* One channel, 32-bit floating point per channel. */
                    RG32F,    /* Two channels, 32-bit floating point per channel. */
                    RGB32F,   /* Three channels,  32-bit floating point per channel. */
                    RGBA32F   /* Four channels,  32-bit floating point per channel. */
                };

                inline FloatPixelFormat(Type value) : enumValue(value)
                {
                }

                inline operator Type() const
                {
                    return enumValue;
                }

            private:
                Type enumValue;
        };
    }
}



#endif  /* EPIC_IMAGE_FLOAT_PIXELFORMAT_H */

