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

    ASCIIString::ASCIIString()
    : stringData()
    {

    }

    ASCIIString::ASCIIString(const char *str)
    : stringData(str, stringLength(str) + 1)
    {
    }

    ASCIIString::ASCIIString(const ASCIIString& other)
    : stringData(other.stringData)
    {
    }

    ASCIIString::~ASCIIString()
    {
    }

    ASCIIString& ASCIIString::operator=(const char *str)
    {
        size_t len = stringLength(str) + 1;

        stringData = Array<char>(str, len);

        return *this;
    }

    ASCIIString& ASCIIString::operator=(const ASCIIString& other)
    {
        if(this != &other) {
            stringData = other.stringData;
        }

        return *this;
    }

    bool ASCIIString::operator==(const char *str) const
    {
        size_t len = stringLength(str);

        if(length() == len) {
            return memoryEquals(data(), str, len);
        }

        return false;
    }

    bool ASCIIString::operator==(const ASCIIString& string) const
    {
        if(length() == string.length()) {
            return (stringData == string.stringData);
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

    ASCIIString ASCIIString::wrap(char* str)
    {
        ASCIIString ret;
        size_t len = stringLength(str) + 1;

        ret.stringData = Array<char>::wrap(str, len);

        return ret;
    }
}
}

