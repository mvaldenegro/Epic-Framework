/*
 * File:   PixelFormat.h
 * Author: mvaldenegro
 *
 * Created on 2 de junio de 2011, 12:49 PM
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

