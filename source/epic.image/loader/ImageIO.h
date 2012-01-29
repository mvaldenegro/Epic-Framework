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

#ifndef IMAGEIO_H_
#define IMAGEIO_H_

#include <epic.core/ASCIIString.h>
#include <epic.core/Array.h>

namespace Epic {
    namespace Image {

        class Image;

        namespace Loader {

            class ImageReader;
            class ImageWriter;

            class ImageIO
            {
                public:
                    static Image *load(const Epic::Core::ASCIIString& fileName);
                    static void write(const Epic::Core::ASCIIString& fileName,
                                      const Epic::Core::ASCIIString& format, Image *image);

                private:

                    static Epic::Core::Array<ImageReader *> loaders;
                    static Epic::Core::Array<ImageWriter *> writers;

                    ImageIO();
                    ~ImageIO();

            };

        } /* namespace Loader */
    } /* namespace Image */
} /* namespace Epic */
#endif /* IMAGEIO_H_ */
