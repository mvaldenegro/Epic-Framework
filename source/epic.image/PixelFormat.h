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

#ifndef EPIC_IMAGE_PIXELFORMAT_H
#define	EPIC_IMAGE_PIXELFORMAT_H

namespace Epic {
    namespace Image {

        /*! Pixel format for images.
         */

        class PixelFormat
        {
            public:
                enum Type
                {
                    R8,     /* One channel, 8 bits per channel. */
                    RG8,    /* Two channels, 8 bits per channel. */
                    RGB8,   /* Three channels,  8 bits per channel. */
                    RGBA8,  /* Four channels,  8 bits per channel. */
                    BGR8,   /* Three channels,  8 bits per channel. */
                    BGRA8  /* Four channels,  8 bits per channel. */
                };

                inline PixelFormat(Type value) : enumValue(value)
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



#endif	/* EPIC_IMAGE_PIXELFORMAT_H */

