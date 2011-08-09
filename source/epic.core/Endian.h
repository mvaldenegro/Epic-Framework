/*
 * File:   Endian.h
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 03:26 PM
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

