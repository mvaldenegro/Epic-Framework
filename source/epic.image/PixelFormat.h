/* 
 * File:   PixelFormat.h
 * Author: mvaldenegro
 *
 * Created on 2 de junio de 2011, 12:49 PM
 */

#ifndef PIXELFORMAT_H
#define	PIXELFORMAT_H

namespace Epic {
    namespace Image {
        enum PixelFormat
        {
            R8,     /* One channel, 8 bits per channel. */
            RG8,    /* Two channels, 8 bits per channel. */
            RGB8,   /* Three channels,  8 bits per channel. */
            RGBA8,  /* Four channels,  8 bits per channel. */
            BGR8,   /* Three channels,  8 bits per channel. */
            BGRA8,  /* Four channels,  8 bits per channel. */

            RGB565
        };
    };
};



#endif	/* PIXELFORMAT_H */

