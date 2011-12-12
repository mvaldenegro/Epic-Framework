/*
 * File:   RGBA8Image.h
 * Author: mvaldenegro
 *
 * Created on 28 de julio de 2011, 07:49 PM
 */

#ifndef EPIC_IMAGE_RGBA8IMAGE_H
#define	EPIC_IMAGE_RGBA8IMAGE_H

#include <epic.image/Image.h>

namespace Epic {
    namespace Image {

        /*! 32-bit per pixel RGBA image.
         */
        class RGBA8Image : public Image
        {
            public:
                /*! Constructor.
                 *
                 * Constructs a image given the width and height.
                 */
                RGBA8Image(size_t width, size_t height);

                /*! Destructor.
                 */
                virtual ~RGBA8Image();

                size_t bytesPerPixel() const;
                Pixel pixel(size_t row, size_t column) const;
                void setPixel(size_t row, size_t column, const Pixel& pixel);
        };
    }
}

#endif	/* EPIC_IMAGE_RGBA8IMAGE_H */

