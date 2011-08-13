/*
 * File:   ArrayTest.cpp
 * Author: mvaldenegro
 *
 * Created on 24 de julio de 2011, 09:34 PM
 */

#include <epic.core/Array.h>
#include <iostream>

using namespace std;

template<typename T>
void print(const Epic::Core::Array<T>& array)
{
    cout << "( ";

    for(size_t i = 0; i < array.count(); i++) {
        cout << array[i];
        cout << " ";
    }

    cout << ")" << endl;
}

Epic::Core::Array<int> create()
{
    return Epic::Core::Array<int>() << 1 << 2 << 3;
}

int main(int argc, char** argv)
{
    Epic::Core::Array<int> a = create();

    print(a);

    cout << "Array empty? " << a.isEmpty() << endl;

    Epic::Core::Array<int> b = a;

    print(b);

    cout << "Modificacion" << endl;

    b[0] = 0;

    print(a);
    print(b);

    b[0] = 6;
    b[1] = 7;
    b[2] = 8;

    print(a);
    print(b);

    b.append(9);

    print(a);
    print(b);

    Epic::Core::Array<int> nil;

    cout << "Empty array pointer " << nil.data() << endl;
    cout << "Empty array size " << nil.count() << endl;
    cout << "Empty array empty? " << nil.isEmpty() << endl;

    return 0;
}

