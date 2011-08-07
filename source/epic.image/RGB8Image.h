/*
 * File:   RGB8Image.h
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 03:23 PM
 */

#ifndef EPIC_IMAGE_RGB8IMAGE_H
#define	EPIC_IMAGE_RGB8IMAGE_H

#include <epic.image/Image.h>

namespace Epic {
    namespace Image {
        class RGB8Image : public Image
        {
            public:
                RGB8Image(size_t width, size_t height);
                ~RGB8Image();

                size_t bytesPerPixel() const;
                Pixel pixel(size_t row, size_t column) const;
                void setPixel(size_t row, size_t column, const Pixel& pixel);
        };
    }
}

#endif	/* EPIC_IMAGE_RGB8IMAGE_H */

