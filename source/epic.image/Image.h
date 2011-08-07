/*
 * File:   Image.h
 * Author: mvaldenegro
 *
 * Created on 2 de junio de 2011, 12:47 PM
 */

#ifndef EPIC_IMAGE_IMAGE_H
#define	EPIC_IMAGE_IMAGE_H

#include <epic.core/Core.h>
#include <epic.image/PixelFormat.h>
#include <epic.image/Pixel.h>

namespace Epic {
    namespace Image {
        class Image
        {
            private:
                size_t      imageWidth, imageHeight;
                PixelFormat imageFormat;
                Epic::Core::Byte *imagePixelData;

            public:
                Image(size_t width, size_t height, PixelFormat format);
                Image(const Image& image);

                virtual ~Image();

                inline size_t width() const
                {
                    return imageWidth;
                }

                inline void setWidth(size_t width)
                {
                    imageWidth = width;
                }

                inline size_t height() const
                {
                    return imageHeight;
                }

                inline void setHeight(size_t height)
                {
                    imageHeight = height;
                }

                inline PixelFormat format() const
                {
                    return imageFormat;
                }

                inline Epic::Core::Byte *pixelData()
                {
                    return imagePixelData;
                }

                inline const Epic::Core::Byte *pixelData() const
                {
                    return imagePixelData;
                }

                inline size_t pixelDataSize() const
                {
                    return width() * height() * bytesPerPixel();
                }

                virtual size_t bytesPerPixel() const = 0;

                virtual Pixel pixel(size_t row, size_t column) const = 0;
                virtual void setPixel(size_t row, size_t column, const Pixel& pixel) = 0;

                Image *converted(PixelFormat format) const;
                static Image *createFromFormat(size_t width, size_t height, PixelFormat format);

            protected:
                inline void setPixelData(Epic::Core::Byte *pixelData)
                {
                    imagePixelData = pixelData;
                }

                inline size_t index(size_t row, size_t column) const
                {
                    return bytesPerPixel() * (row * width() + column);
                }
        };
    }
}

#endif	/* EPIC_IMAGE_IMAGE_H */

