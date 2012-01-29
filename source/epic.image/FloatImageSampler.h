/*
 * Copyright (C) 2011 Matias Valdenegro <matias.valdenegro@gmail.com>
 * This file is part of Epic Framework.
 *
 * Epic Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Epic Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Epic Framework.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FLOATIMAGESAMPLER_H_
#define FLOATIMAGESAMPLER_H_

#include <epic.image/FloatImage.h>
#include <epic.image/SamplerParameters.h>

namespace Epic {
    namespace Image {

        /*! Floating point Image sampler.
         *  This class is used to sample images, with filtering and address wrap modes.
         *
         */

        class FloatImageSampler
        {
            private:
                Filter samplerFilter;
                WrapMode samplerWrapMode;

            public:
                FloatImageSampler();
                virtual ~FloatImageSampler();



                PixelF sample(float s, float t) const;
                PixelF sample(size_t s, size_t t) const;

        };

    } /* namespace Image */
} /* namespace Epic */
#endif /* FLOATIMAGESAMPLER_H_ */
