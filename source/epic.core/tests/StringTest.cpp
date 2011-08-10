/*
 * File:   StringTest.cpp
 * Author: mvaldenegro
 *
 * Created on 9 de agosto de 2011, 10:38 PM
 */

#include <iostream>
#include <epic.core/String.h>

using namespace std;
using Epic::Core::String;
using Epic::Core::ASCIIString;
using Epic::Core::Array;

/*
 *
 */
int main(int argc, char** argv)
{
    String hello = ASCIIString("hola mundo");

    Array<char> str = hello.toAscii();

    cout << str.count() << endl;
    cout << str.data() << endl;

    return 0;
}

