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

#ifndef EPIC_CORE_ARRAYSLICE_H_
#define EPIC_CORE_ARRAYSLICE_H_

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {

        template<typename T> class Array;

        template<typename T>
        class ArraySlice
        {
            friend class Array<T>;

            public:
                ~ArraySlice()
                {
                }

                EPIC_INLINE size_t count() const
                {
                    return length;
                }

                T& operator[](size_t idx)
                {
                    EPIC_BOUNDS_CHECK(idx, length);

                    return targetArray->at(startIndex + idx);
                }

                const T& operator[](size_t idx) const
                {
                    EPIC_BOUNDS_CHECK(idx, length);

                    return targetArray->at(startIndex + idx);
                }

            private:
                ArraySlice(Array<T> *target, size_t start, size_t end)
                : targetArray(target), startIndex(start), endIndex(end), length(end - start)
                {
                }

                Array<T> *targetArray;
                size_t startIndex;
                size_t endIndex;
                size_t length;
        };
    }
}

#endif /* EPIC_CORE_ARRAYSLICE_H_ */
