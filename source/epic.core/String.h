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

#ifndef EPIC_CORE_STRING_H
#define	EPIC_CORE_STRING_H

#include <epic.core/Core.h>
#include <epic.core/Array.h>
#include <epic.core/ASCIIString.h>

namespace Epic {
    namespace Core {
        class String {
            public:
                String();
                String(const ASCIIString& str);
                String(const String& other);
                ~String();

                String& operator=(const ASCIIString& str);
                String& operator=(const String& str);

                inline size_t length() const
                {
                    return data.count();
                }

                inline Epic::Core::UInt16& operator[](int i)
                {
                    return at(i);
                }

                inline const Epic::Core::UInt16& operator[](int i) const
                {
                    return at(i);
                }

                inline Epic::Core::UInt16& at(int i)
                {
                    return data[i];
                }

                inline const Epic::Core::UInt16& at(int i) const
                {
                    return data[i];
                }

                Array<char> toAscii() const;

                static String fromAscii(const ASCIIString& str);

            private:
                Array<Epic::Core::UInt16> data;
        };
    }
}


#endif	/* EPIC_CORE_STRING_H */

