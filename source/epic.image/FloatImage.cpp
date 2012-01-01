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

#include "FloatImage.h"
#include "RGBA32FImage.h"
#include "RGB32FImage.h"
#include "RG32FImage.h"
#include "R32FImage.h"

namespace Epic {
    namespace Image {

        FloatImage::FloatImage(size_t width, size_t height, size_t components, FloatPixelFormat format)
        : imageWidth(width), imageHeight(height), imageComponents(components),
          imageFormat(format), imagePixelData(nullptr)
        {
            imagePixelData = new float[components * width * height];
        }

        FloatImage::~FloatImage()
        {
            delete [] imagePixelData;
        }

        FloatImage* FloatImage::createFromFormat(size_t width, size_t height, FloatPixelFormat format)
        {
            switch(format) {
                case FloatPixelFormat::RGBA32F: {
                    return new RGBA32FImage(width, height);
                }

                case FloatPixelFormat::RGB32F: {
                    return new RGB32FImage(width, height);
                }

                case FloatPixelFormat::RG32F: {
                    return new RG32FImage(width, height);
                }

                case FloatPixelFormat::R32F: {
                    return new R32FImage(width, height);
                }

                default: {
                    return nullptr;
                }
            }
        }
    } /* namespace Image */
} /* namespace Epic */
