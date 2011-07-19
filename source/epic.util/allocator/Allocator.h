/* 
 * File:   Allocator.h
 * Author: hunts
 *
 * Created on 7 de febrero de 2011, 07:26 PM
 */

#ifndef ALLOCATOR_H
#define	ALLOCATOR_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Util {
        namespace Allocator {
            class Allocator {
                public:
                    virtual void *allocate(size_t size, unsigned int flags = 0) = 0;
                    virtual void *allocate(size_t size, size_t alignment, unsigned int flags) = 0;
                    virtual void deallocate(void *ptr, size_t size);
            };
        }
    }
}

#endif	/* ALLOCATOR_H */

