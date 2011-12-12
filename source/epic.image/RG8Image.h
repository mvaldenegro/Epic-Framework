/*
 * File:   RG8Image.h
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 04:04 PM
 */

#ifndef EPIC_IMAGE_RG8IMAGE_H
#define	EPIC_IMAGE_RG8IMAGE_H

#include <epic.image/Image.h>

namespace Epic {
    namespace Image {

        /*! 16-bit per pixel RG image.
         */
        class RG8Image : public Image
        {
            public:
                /*! Constructor.
                 *
                 * Constructs a image given the width and height.
                 */
                RG8Image(size_t width, size_t height);

                /*! Destructor.
                 */
                virtual ~RG8Image();

                size_t bytesPerPixel() const;
                Pixel pixel(size_t row, size_t column) const;
                void setPixel(size_t row, size_t column, const Pixel& pixel);
        };
    }
}

#endif	/* RG8IMAGE_H */

