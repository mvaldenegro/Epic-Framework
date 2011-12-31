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

#ifndef ASSERT_H
#define	ASSERT_H

#include <epic.core/Core.h>

#include <iostream>
#include <cstdlib>

namespace Epic {
    namespace Core {
        inline void EPIC_NO_RETURN assert(const char *conditionText, const char *file, int line)
        {
            std::cerr << "Assertion " << conditionText << " failed at " << file << ":" << line << std::endl;
            std::exit(-1);
        }

        inline void nothing()
        {
            /* Yes, nothing :) */
        }
    }
}

#define EPIC_HARD_ASSERT(condition) \
    ((!(condition)) ? Epic::Core::assert(#condition, __FILE__, __LINE__) : Epic::Core::nothing())

#ifndef EPIC_NO_DEBUG
#   define EPIC_ASSERT(condition) (EPIC_HARD_ASSERT(condition))
#else
#   define EPIC_ASSERT(condition) (nothing())
#endif

#endif	/* ASSERT_H */

