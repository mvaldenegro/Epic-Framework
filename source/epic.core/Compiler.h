/* 
 * File:   Compiler.h
 * Author: hunts
 *
 * Created on 23 de agosto de 2010, 10:48 PM
 */

#ifndef EPIC_CORE_COMPILER_H
#define	EPIC_CORE_COMPILER_H

#define EPIC_CORE_COMPILER_DOESNT_SUPPORT_NULLPTR
#ifdef EPIC_CORE_COMPILER_DOESNT_SUPPORT_NULLPTR
const class {
    public:
        template<class T>
        operator T*() const
        {
            return 0;
        }

        template<class C, class T>
        operator T C::*() const
        {
            return 0;
        }
    private:
        void operator&() const;
} nullptr = {};
#endif

#endif	/* EPIC_CORE_COMPILER_H */

