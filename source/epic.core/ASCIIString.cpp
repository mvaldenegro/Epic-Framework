/*
 * File:   ASCIIString.cpp
 * Author: hunts
 *
 * Created on 29 de enero de 2011, 09:14 PM
 */

#include "ASCIIString.h"
#include "Algorithms.h"

static size_t stringLength(const char *str)
{
    size_t ret = 0;

    while(*str++ != '\0') {
        ret++;
    }

    return ret;
}

namespace Epic {
namespace Core {

    ASCIIString::ASCIIString(const char *str)
    : data(str), dataLength(stringLength(str))
    {
    }

    ASCIIString::ASCIIString(const ASCIIString& other)
    : data(other.data), dataLength(other.dataLength)
    {
    }

    ASCIIString::~ASCIIString()
    {
    }

    ASCIIString& ASCIIString::operator=(const char *str)
    {
        data = str;
        dataLength = stringLength(str);

        return *this;
    }

    ASCIIString& ASCIIString::operator=(const ASCIIString& other)
    {
        data = other.data;
        dataLength = other.dataLength;

        return *this;
    }

    bool ASCIIString::operator==(const char *str) const
    {
        size_t len = min(stringLength(str), dataLength);

        return memoryEquals(data, str, len);
    }

    bool ASCIIString::operator==(const ASCIIString& string) const
    {
        if(length() == string.length()) {
            return memoryEquals(data, string.rawString(), length());
        }

        return false;
    }

    bool ASCIIString::operator!=(const char *str) const
    {
        return !(*this == str);
    }

    bool ASCIIString::operator!=(const ASCIIString& string) const
    {
        return !(*this == string);
    }
}
}

