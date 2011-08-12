/*
 * File:   ASCIIString.h
 * Author: hunts
 *
 * Created on 29 de enero de 2011, 09:14 PM
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

