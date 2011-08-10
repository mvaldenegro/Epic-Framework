/*
 * File:   ASCIIString.h
 * Author: hunts
 *
 * Created on 29 de enero de 2011, 09:14 PM
 */

#ifndef ASCIISTRING_H
#define	ASCIISTRING_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {

        /*! Container for raw C strings (const char *).
         */

        class ASCIIString
        {
            public:
                ASCIIString(const char *str);
                ASCIIString(const ASCIIString& other);
                ~ASCIIString();

                ASCIIString& operator=(const char *str);
                ASCIIString& operator=(const ASCIIString& other);

                inline size_t length() const
                {
                    return this->dataLength;
                }

                inline const char *rawString() const
                {
                    return this->data;
                }

                inline char operator[](int i) const
                {
                    return this->data[i];
                }

                bool operator==(const char *str) const;
                bool operator==(const ASCIIString& string) const;

                bool operator!=(const char *str) const;
                bool operator!=(const ASCIIString& string) const;

            private:
                const char *data;
                size_t dataLength;

        };
    }
}



#endif	/* ASCIISTRING_H */

