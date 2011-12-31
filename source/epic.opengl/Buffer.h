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

#ifndef EPIC_OPENGL_BUFFER_H_
#define EPIC_OPENGL_BUFFER_H_

#include <epic.opengl/OpenGL.h>
#include <epic.core/Core.h>

namespace Epic {
    namespace OpenGL {

        class Buffer
        {
            public:
                Buffer(GLenum target, GLenum usage, size_t bufferSize, void *data = nullptr);
                Buffer(Buffer&& other);
                ~Buffer();

                EPIC_INLINE GLenum target() const
                {
                    return mBufferTarget;
                }

                EPIC_INLINE size_t size() const
                {
                    return mBufferSize;
                }

                EPIC_INLINE GLuint handle() const
                {
                    return mBufferID;
                }

                void bind();
                void bind(GLenum newTarget);
                void unbind();

                void setData(size_t bufferSize, GLenum usage, void *data);
                void updateData(size_t offset, size_t size, void *data);

            private:
                EPIC_NON_COPYABLE(Buffer);
                GLuint mBufferID;
                GLenum mBufferTarget;
                size_t mBufferSize;
        };
    }
}
#endif /* EPIC_OPENGL_BUFFER_H_ */
