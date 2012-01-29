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

#include "ImageIO.h"

namespace Epic {
    namespace Image {
        namespace Loader {

            Epic::Core::Array<ImageLoader *> ImageIO::loaders = Epic::Core::Array<ImageLoader *>();
            Epic::Core::Array<ImageWriter *> ImageIO::writers = Epic::Core::Array<ImageWriter *>();

            Image *ImageIO::load(const Epic::Core::ASCIIString& fileName)
            {
                for(size_t i = 0; i < loaders.count(); i++) {
                    if(loaders[i]->matchHeader(fileName)) {
                        return loaders[i]->read(fileName);
                    }
                }

                return nullptr;
            }

            void ImageIO::write(const Epic::Core::ASCIIString& fileName, const Epic::Core::ASCIIString& format, Image *image)
            {
                for(size_t i = 0; i < writers.count(); i++) {
                    if(format == writers[i]->formatName()) {

                        writers[i]->write(fileName, image);

                        return;
                    }
                }
            }

            ImageIO::ImageIO()
            {
            }

            ImageIO::~ImageIO()
            {
            }

        } /* namespace Loader */
    } /* namespace Image */
} /* namespace Epic */
