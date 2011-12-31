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

#ifndef ALGORITHMS_H
#define	ALGORITHMS_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {
        template<typename T>
        T min(const T& a, const T& b)
        {
            return a < b ? a : b;
        }

        template<typename T>
        T max(const T& a, const T& b)
        {
            return a < b ? b : a;
        }

        template<typename T>
        void copyMemory(T *destiny, const T* source, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                destiny[i] = source[i];
            }
        }

        template<typename T>
        bool memoryEquals(const T *a, const T *b, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }

            return true;
        }

        template<typename T>
        void fillMemory(T *destiny, const T& constData, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                destiny[i] = constData;
            }
        }
    }
}

#endif	/* ALGORITHMS_H */

