/*
 * ImageProcessor.h
 *
 *  Created on: 21-12-2011
 *      Author: mvaldenegro
 */

#ifndef IMAGEPROCESSOR_H_
#define IMAGEPROCESSOR_H_

#include <epic.image/FloatImage.h>

namespace Epic {
    namespace Image {
        namespace Processing {

            class ImageProcessor
            {
                public:
                    ImageProcessor();
                    virtual ~ImageProcessor();

                    virtual FloatImage *process(FloatImage *image) const = 0;
            };

        } /* namespace Processing */
    } /* namespace Image */
} /* namespace Epic */
#endif /* IMAGEPROCESSOR_H_ */
