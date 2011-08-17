/*
 * Buffer.cpp
 *
 *  Created on: 16-08-2011
 *      Author: mvaldenegro
 */

#include "Buffer.h"

namespace Epic {
    namespace OpenGL {

        Buffer::Buffer(GLenum target, GLenum usage, size_t bufferSize, void *data)
        : mBufferID(0), mBufferTarget(target), mBufferSize(bufferSize)
        {
            glGenBuffers(1, &mBufferID);
            glBindBuffer(target, mBufferID);
            glBufferData(target, bufferSize, data, usage);
        }

        Buffer::Buffer(Buffer&& other)
        : mBufferID(other.handle()), mBufferTarget(other.target()), mBufferSize(other.size())
        {
            other.mBufferID = 0;
        }

        void Buffer::bind()
        {
            glBindBuffer(target(), handle());
        }

        void Buffer::bind(GLenum newTarget)
        {
            unbind();
            mBufferTarget = newTarget;

            glBindBuffer(target(), handle());
        }

        void Buffer::unbind()
        {
            glBindBuffer(target(), 0);
        }

        void Buffer::setData(size_t bufferSize, GLenum usage, void *data)
        {
            bind();

            glBufferData(target(), bufferSize, data, usage);
        }

        void Buffer::updateData(size_t offset, size_t size, void *data)
        {
            bind();

            glBufferSubData(target(), offset, size, data);
        }

        Buffer::~Buffer()
        {
            glDeleteBuffers(1, &mBufferID);
        }

    }
}
