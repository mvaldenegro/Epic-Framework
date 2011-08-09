/*
 * File:   Macros.h
 * Author: hunts
 *
 * Created on 23 de agosto de 2010, 11:18 PM
 */

#ifndef EPIC_CORE_MACROS_H
#define	EPIC_CORE_MACROS_H

#ifndef EPIC_DEBUG
    #define EPIC_INLINE                         inline
#else
    #define EPIC_INLINE
#endif

#define EPIC_EXPORT                         __attribute__ ((visibility ("default")))
#define EPIC_NO_EXPORT                      __attribute__ ((visibility ("hidden")))

#define EPIC_ALIGN(n)                       __attribute__ ((aligned(n)))
#define EPIC_PACKED                         __attribute__ ((__packed__))

#define EPIC_DEPRECATED                     __attribute__ ((deprecated))
#define EPIC_DEPRECATED_MESSAGE(msg)        __attribute__ ((deprecated(msg)))

#define EPIC_NO_RETURN                      __attribute__((__noreturn__))

#endif	/* EPIC_CORE_MACROS_H */

