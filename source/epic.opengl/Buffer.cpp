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
