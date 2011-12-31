/*
 * Kernel.h
 *
 *  Created on: 03-12-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_IMAGE_PROCESSING_KERNEL_H_
#define EPIC_IMAGE_PROCESSING_KERNEL_H_

#include <epic.math/Matrix.h>
#include <epic.math/Math.h>

namespace Epic {
    namespace Image {
        namespace Processing {

            class Kernel
            {
                public:
                    template<typename Scalar>
                    static Epic::Math::Matrix<Scalar> gaussian(size_t size, Scalar sigmaSquared)
                    {
                        Epic::Math::Matrix<Scalar> ret(size, size);

                        /* R = rows, C = columns. */
                        Scalar centerR = (size - 1) / 2;
                        Scalar centerC = (size - 1) / 2 ;

                        Scalar normalizer = 1.0 / (2 * 3.1415 * sigmaSquared);

                        for(size_t i = 0; i < size; i++) {
                            for(size_t j = 0; j < size; j++) {
                                Scalar x = static_cast<Scalar>(centerR - i);
                                Scalar y = static_cast<Scalar>(centerC - j);

                                Scalar t = (x*x + y*y) / (2 * sigmaSquared);

                                ret(i, j) = normalizer * Math::exponential(-t);
                            }
                        }

                        return ret;
                    }

                private:
                    ~Kernel();
                    Kernel();
            };

        } /* namespace Processing */
    } /* namespace Image */
} /* namespace Epic */
#endif /* EPIC_IMAGE_PROCESSING_KERNEL_H_ */
