/*
 * File:   String.h
 * Author: hunts
 *
 * Created on 23 de agosto de 2010, 10:34 PM
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

