/*
 * ImageF.h
 *
 *  Created on: 09-12-2011
 *      Author: mvaldenegro
 */

#ifndef IMAGEF_H_
#define IMAGEF_H_

#include <epic.core/Core.h>

#include <epic.image/FloatPixelFormat.h>
#include <epic.image/PixelF.h>

namespace Epic {
    namespace Image {

        /*! Floating point image.
         */
        class FloatImage
        {
            private:
                size_t  imageWidth, imageHeight;
                size_t  imageComponents;
                FloatPixelFormat imageFormat;
                float * imagePixelData;

            public:
                FloatImage(size_t width, size_t height, size_t components, FloatPixelFormat format);

                /*! Destructor.
                 *  This destructor will delete [] the imagePixelData array.
                 */
                virtual ~FloatImage();

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

                /*! Byte pointer to the pixel data of this image.
                 */
                EPIC_INLINE float *pixelData()
                {
                    return imagePixelData;
                }

                /*! Constant byte pointer to the pixel data of this image.
                 */
                EPIC_INLINE const float *pixelData() const
                {
                    return imagePixelData;
                }

                /*! Size in bytes of the pixel data in this image.
                 */
                EPIC_INLINE size_t pixelDataSize() const
                {
                    return width() * height() * bytesPerPixel();
                }

                /*! Number of components in this image.
                 */
                EPIC_INLINE size_t components() const
                {
                    return imageComponents;
                }

                /*! Size in bytes of a image pixel.
                 */
                EPIC_INLINE size_t bytesPerPixel() const
                {
                    return sizeof(float) * components();
                }

                /*! Returns the pixel indexed by row and column.
                 */
                virtual PixelF pixel(size_t row, size_t column) const = 0;

                /*! Sets the pixel indexed by row and column.
                 */
                virtual void setPixel(size_t row, size_t column, const PixelF& pixel) = 0;

            protected:
                /*! Sets the image pixel data.
                 */
                EPIC_INLINE void setPixelData(float *pixelData)
                {
                    imagePixelData = pixelData;
                }

                /*! Returns an appropiate linear index from a 2D row-column index, used to index the image pixel data.
                 *
                 * The performed calculation is bytesPerPixel() * (row * width + column).
                 */
                EPIC_INLINE size_t index(size_t row, size_t column) const
                {
                    return components() * (row * width() + column);
                }


        };

    } /* namespace Image */
} /* namespace Epic */
#endif /* IMAGEF_H_ */
