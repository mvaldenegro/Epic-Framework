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

#define EPIC_NON_COPYABLE(clazz)            clazz(const clazz& copy)

#endif	/* EPIC_CORE_MACROS_H */

