/*
 * File:   PixelFormat.h
 * Author: mvaldenegro
 *
 * Created on 2 de junio de 2011, 12:49 PM
 */

#ifndef EPIC_IMAGE_FLOAT_PIXELFORMAT_H
#define EPIC_IMAGE_FLOAT_PIXELFORMAT_H

namespace Epic {
    namespace Image {

        /*! Pixel format for images.
         */

        class FloatPixelFormat
        {
            public:
                enum Type
                {
                    R32F,     /* One channel, 32-bit floating point per channel. */
                    RG32F,    /* Two channels, 32-bit floating point per channel. */
                    RGB32F,   /* Three channels,  32-bit floating point per channel. */
                    RGBA32F   /* Four channels,  32-bit floating point per channel. */
                };

                inline FloatPixelFormat(Type value) : enumValue(value)
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



#endif  /* EPIC_IMAGE_FLOAT_PIXELFORMAT_H */

