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

#ifndef ASCIISTRING_H
#define	ASCIISTRING_H

#include <epic.core/Core.h>
#include <epic.core/Array.h>

namespace Epic {
    namespace Core {

        /*! ASCII String.
         *
         * This class contains a char *, representing a ASCII/Latin-1 string.
         */

        class ASCIIString
        {
            public:
                ASCIIString();
                ASCIIString(const char *str);
                ASCIIString(const ASCIIString& other);
                ~ASCIIString();

                ASCIIString& operator=(const char *str);
                ASCIIString& operator=(const ASCIIString& other);

                inline bool isEmpty()
                {
                    return stringData.isEmpty();
                }

                inline size_t length() const
                {
                    /* Account for the '\0' inside the array. */

                    return stringData.count() - 1;
                }

                inline char *data()
                {
                    return stringData.data();
                }

                inline const char *data() const
                {
                    return stringData.data();
                }

                inline char& operator[](int i)
                {
                    return stringData[i];
                }

                inline char operator[](int i) const
                {
                    return stringData[i];
                }

                bool operator==(const char *str) const;
                bool operator==(const ASCIIString& string) const;

                bool operator!=(const char *str) const;
                bool operator!=(const ASCIIString& string) const;

                EPIC_INLINE operator const char *()
                {
                    return data();
                }

                static ASCIIString wrap(char *str);

            private:
                Array<char> stringData;

        };
    }
}



#endif	/* ASCIISTRING_H */

