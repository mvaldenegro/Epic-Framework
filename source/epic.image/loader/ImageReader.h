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

#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include <epic.core/ASCIIString.h>

#include <epic.image/Image.h>

namespace Epic {
    namespace Image {
        namespace Loader {

            class ImageReader
            {
                public:
                    ImageReader();
                    virtual ~ImageReader();

                    virtual const char *formatName() const = 0;
                    virtual bool matchHeader(const Epic::Core::ASCIIString& fileName) const = 0;

                    virtual Epic::Image::Image *read(const Epic::Core::ASCIIString& fileName) const = 0;


            };

        } /* namespace Loader */
    } /* namespace Image */
} /* namespace Epic */
#endif /* IMAGELOADER_H_ */
