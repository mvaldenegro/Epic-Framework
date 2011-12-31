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

#ifndef EPIC_CORE_ENDIAN_H
#define	EPIC_CORE_ENDIAN_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {
        class Endian
        {
            public:
                enum Type {
                    BigEndian,
                    LittleEndian
                };

                inline static Endian getEndianess()
                {
                    return Endian::LittleEndian;
                }

                inline static Epic::Core::Byte *byteSwap(Epic::Core::Byte *destiny, const Epic::Core::Byte *source,
                                                         size_t length)
                {
                    for(size_t i = 0; i < length; i++) {
                        destiny[i] = source[length - 1 - i];
                    }
                }

                template<typename T> inline static T toLittleEndian(T v);
                template<typename T> inline static T toBigEndian(T v);

                EPIC_INLINE Endian(Type t)
                : enumValue(t)
                {
                }

                inline operator Type() const
                {
                    return enumValue;
                }

            private:
                Type enumValue;
        };
    }
}

#endif	/* EPIC_CORE_ENDIAN_H */

