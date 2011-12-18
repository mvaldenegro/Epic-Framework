/*
 * PixelF.h
 *
 *  Created on: 09-12-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_IMAGE_PIXEL_FLOAT_H
#define EPIC_IMAGE_PIXEL_FLOAT_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Image {

        /*! Floating point RGBA image element.
         */
        class PixelF
        {
            public:

                /*! Red component.
                 */
                float r;

                /*! Green component.
                 */
                float g;

                /*! Blue component.
                 */
                float b;

                /*! Alpha component.
                 */
                float a;

                /*! Constructor.
                 *
                 * Constructs a pixel from it's four color components.
                 */
                inline PixelF(float red, float green, float blue, float alpha = 1.0f)
                    : r(red), g(green), b(blue), a(alpha)
                {
                }

                /*! Copy constructor.
                 */
                inline PixelF(const PixelF& pixel)
                    : r(pixel.r), g(pixel.g), b(pixel.b), a(pixel.a)
                {

                }

                /*! Destructor.
                 */

                inline ~PixelF()
                {
                }

                /*! Assignment operator.
                 */
                inline PixelF& operator=(const PixelF& pixel)
                {
                    r = pixel.r;
                    g = pixel.g;
                    b = pixel.b;
                    a = pixel.a;

                    return *this;
                }

                /*! Equality operator.
                 */
                inline bool operator==(const PixelF& pixel)
                {
                    return r == pixel.a &&
                           g == pixel.g &&
                           b == pixel.b &&
                           a == pixel.a;
                }

                /*! Inequality operator
                 */
                inline bool operator!=(const PixelF& pixel)
                {
                    return r != pixel.a &&
                           g != pixel.g &&
                           b != pixel.b &&
                           a != pixel.a;
                }

        } EPIC_PACKED;
    }
}

#endif  /* EPIC_IMAGE_PIXEL_FLOAT_H */

