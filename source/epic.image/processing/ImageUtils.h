/*
 * ImageUtils.h
 *
 *  Created on: 07-11-2011
 *      Author: mvaldenegro
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
