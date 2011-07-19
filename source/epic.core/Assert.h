/* 
 * File:   Assert.h
 * Author: hunts
 *
 * Created on 14 de noviembre de 2010, 12:01 AM
 */

#ifndef ASSERT_H
#define	ASSERT_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {
        inline void EPIC_NO_RETURN assert(const char *conditionText, const char *file, int line)
        {
        }

        inline void nothing()
        {
            /* Yes, nothing :) */
        }
    };
};

#define EPIC_HARD_ASSERT(condition) \
    ((!(condition)) ? Epic::Core::assert(#condition, __FILE__, __LINE__) : Epic::Core::nothing())

#ifndef EPIC_NO_DEBUG
#   define EPIC_ASSERT(condition) (EPIC_HARD_ASSERT(condition))
#else
#   define EPIC_ASSERT(condition) (nothing())
#endif

#endif	/* ASSERT_H */

