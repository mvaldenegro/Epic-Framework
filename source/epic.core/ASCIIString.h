/* 
 * File:   ASCIIString.h
 * Author: hunts
 *
 * Created on 29 de enero de 2011, 09:14 PM
 */

#ifndef ASCIISTRING_H
#define	ASCIISTRING_H

namespace Epic {
    namespace Core {
        class ASCIIString {
            public:
                ASCIIString();
                ASCIIString(const char *cstring);
                ASCIIString(const ASCIIString& other);
                ~ASCIIString();

                ASCIIString& operator=(const ASCIIString& other);
                ASCIIString& operator=(const char *cstring);

                inline int length() const {
                    return this->length;
                }

            private:
                char *data;
                int length;
            
        };
    }
}



#endif	/* ASCIISTRING_H */

