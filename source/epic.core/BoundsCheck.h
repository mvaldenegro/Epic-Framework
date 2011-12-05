/*
 * BoundsCheck.h
 *
 *  Created on: 04-12-2011
 *      Author: mvaldenegro
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
