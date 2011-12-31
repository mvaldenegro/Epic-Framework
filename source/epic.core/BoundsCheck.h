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

#ifndef EPIC_CORE_BOUNDSCHECK_H_
#define EPIC_CORE_BOUNDSCHECK_H_

#include <epic.core/Core.h>

#include <iostream>
#include <cstdlib>

/* Bounds checking macros and utility functions. */

namespace Epic {
    namespace Core {
        inline void checkBounds(size_t index, size_t maximum, const char *file, int line)
        {
            if(!(index < maximum)) {
                std::cerr << "Bounds check failed at " << file << ":" << line << std::endl;
                std::exit(-1);
            }
        }
    }
}

#define EPIC_BOUNDS_CHECK(index, maximum) checkBounds(index, maximum, __FILE__, __LINE__)


#endif /* EPIC_CORE_BOUNDSCHECK_H_ */
