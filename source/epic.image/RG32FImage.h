/*
 * R32FImage.h
 *
 *  Created on: 11-12-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_IMAGE_RG32FIMAGE_H_
#define EPIC_IMAGE_RG32FIMAGE_H_

#include <epic.image/FloatImage.h>

namespace Epic {
    namespace Image {

        class RG32FImage : public FloatImage
        {
            public:
                RG32FImage(size_t width, size_t height);
                virtual ~RG32FImage();

                PixelF pixel(size_t row, size_t column) const;

                void setPixel(size_t row, size_t column, const PixelF& pixel);
                void setPixel(size_t row, size_t column, float r, float g);


        };

    } /* namespace Image */
} /* namespace Epic */
#endif /* EPIC_IMAGE_RG32FIMAGE_H_ */
