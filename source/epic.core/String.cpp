/*
 * File:   String.cpp
 * Author: hunts
 *
 * Created on 23 de agosto de 2010, 10:34 PM
 */

#include "String.h"

using Epic::Core::UInt16;
using Epic::Core::Byte;
using Epic::Core::Array;
using Epic::Core::ASCIIString;

inline static Array<UInt16> fromAsciiHelper(const ASCIIString& str)
{
    Array<UInt16> ret;
    ret.reserve(str.length());

    for(size_t i = 0; i < str.length(); i++) {
        ret << static_cast<UInt16>(str[i]);
    }

    return ret;
}

namespace Epic {
namespace Core {
    String::String()
    : data(Array<UInt16>())
    {
    }

    String::String(const ASCIIString& str)
    : data(fromAsciiHelper(str))
    {
    }

    String::String(const String& orig)
    : data(orig.data)
    {
    }

    String::~String()
    {
    }

    String& String::operator=(const ASCIIString& str)
    {
        data = fromAsciiHelper(str);

        return *this;
    }

    String& String::operator=(const String& str)
    {
        if(this != &str) {
            data = str.data;
        }

        return *this;
    }

    Array<char> String::toAscii() const
    {
        Array<char> ret;
        ret.reserve(length() + 1);

        for(size_t i = 0; i < length(); i++) {
            ret << static_cast<char>(at(i));
        }

        ret << '\0';

        return ret;
    }

    String String::fromAscii(const ASCIIString& str)
    {
        String ret;
        ret.data = fromAsciiHelper(str);

        return ret;
    }
}
}

