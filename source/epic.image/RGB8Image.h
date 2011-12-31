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

#ifndef EPIC_IMAGE_RGB8IMAGE_H
#define	EPIC_IMAGE_RGB8IMAGE_H

#include <epic.image/Image.h>

namespace Epic {
    namespace Image {

        /*! 24-bit per pixel RGB image.
         */
        class RGB8Image : public Image
        {
            public:
                /*! Constructor.
                 *
                 * Constructs a image given the width and height.
                 */
                RGB8Image(size_t width, size_t height);

                /*! Destructor.
                 */
                virtual ~RGB8Image();

                size_t bytesPerPixel() const;
                Pixel pixel(size_t row, size_t column) const;
                void setPixel(size_t row, size_t column, const Pixel& pixel);
        };
    }
}

#endif	/* EPIC_IMAGE_RGB8IMAGE_H */

