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

#ifndef EPIC_IMAGE_IMAGE_H
#define	EPIC_IMAGE_IMAGE_H

#include <epic.core/Core.h>
#include <epic.image/PixelFormat.h>
#include <epic.image/Pixel.h>

namespace Epic {
    namespace Image {

        /*! Base class for Image representations.
         */
        class Image
        {
            private:
                size_t      imageWidth, imageHeight;
                PixelFormat imageFormat;
                Epic::Core::Byte *imagePixelData;

            public:

                /*! Constructor.
                 *
                 * Constructs a image given  the width, height and format.
                 */
                Image(size_t width, size_t height, PixelFormat format);

                /*! Destructor.
                 */
                virtual ~Image();

                /*! Width of this image.
                 */
                EPIC_INLINE size_t width() const
                {
                    return imageWidth;
                }

                /*! Height of this image.
                 */
                EPIC_INLINE size_t height() const
                {
                    return imageHeight;
                }

                /*! Pixel format of this image.
                 */
                EPIC_INLINE PixelFormat format() const
                {
                    return imageFormat;
                }

                /*! Byte pointer to the pixel data of this image.
                 */
                EPIC_INLINE Epic::Core::Byte *pixelData()
                {
                    return imagePixelData;
                }

                /*! Constant byte pointer to the pixel data of this image.
                 */
                EPIC_INLINE const Epic::Core::Byte *pixelData() const
                {
                    return imagePixelData;
                }

                /*! Size in bytes of the pixel data in this image.
                 */
                EPIC_INLINE size_t pixelDataSize() const
                {
                    return width() * height() * bytesPerPixel();
                }

                /*! Size in bytes of a image pixel.
                 */
                virtual size_t bytesPerPixel() const = 0;

                /*! Returns the pixel indexed by row and column.
                 */
                virtual Pixel pixel(size_t row, size_t column) const = 0;

                /*! Sets the pixel indexed by row and column.
                 */
                virtual void setPixel(size_t row, size_t column, const Pixel& pixel) = 0;

                /*! Returns a new instance of this image, converted to the given pixel format.
                 */
                Image *converted(PixelFormat format) const;

                /*! Creates an appropiate subclass of Image, according to the pixel format, and returns it.
                 */
                static Image *createFromFormat(size_t width, size_t height, PixelFormat format);

            protected:

                /*! Sets the image pixel data.
                 */
                EPIC_INLINE void setPixelData(Epic::Core::Byte *pixelData)
                {
                    imagePixelData = pixelData;
                }

                /*! Returns an appropiate linear index from a 2D row-column index, used to index the image pixel data.
                 *
                 * The performed calculation is bytesPerPixel() * (row * width + column).
                 */
                EPIC_INLINE size_t index(size_t row, size_t column) const
                {
                    return bytesPerPixel() * (row * width() + column);
                }
        };
    }
}

#endif	/* EPIC_IMAGE_IMAGE_H */

