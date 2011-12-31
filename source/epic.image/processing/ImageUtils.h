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

#ifndef EPIC_IMAGE_IMAGEUTILS_H_
#define EPIC_IMAGE_IMAGEUTILS_H_

#include <epic.image/Image.h>
#include <epic.math/Matrix.h>

namespace Epic {
	namespace Image {
		namespace Processing {

			class ImageUtils {
				public:
			        template<typename Scalar>
					static Epic::Image::Image *convolution(Image *image, const Epic::Math::Matrix<Scalar>& kernel);

				private:
			        ImageUtils();
			        ~ImageUtils();
			};

		} /* namespace Processing */
	} /* namespace Image */
} /* namespace Epic */

#endif /* EPIC_IMAGE_IMAGEUTILS_H_ */
