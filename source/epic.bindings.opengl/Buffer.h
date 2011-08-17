/*
 * Buffer.h
 *
 *  Created on: 16-08-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_OPENGL_BUFFER_H_
#define EPIC_OPENGL_BUFFER_H_

#include <epic.bindings.opengl/OpenGL.h>
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
