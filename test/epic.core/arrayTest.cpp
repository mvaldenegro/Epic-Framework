/*
 * File:   ArrayTest.cpp
 * Author: mvaldenegro
 *
 * Created on 24 de julio de 2011, 09:34 PM
 */

#include <epic.core/Array.h>
#include <iostream>
#include <algorithm>

using namespace std;

using Epic::Core::Array;
using Epic::Core::ArraySlice;

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

    cout << "Iterator test" << endl;

    for(Epic::Core::Array<int>::Iterator it = a.begin(); it < a.end(); it += 2) {
        cout << *it << endl;
    }

    cout << "Const iterator test" << endl;

    for(Epic::Core::Array<int>::ConstIterator it = a.constBegin(); it != a.constEnd(); it++) {
        cout << *it << endl;
    }

    cout << "Test std::find" << endl;

    Array<int>::Iterator ret = std::find(a.begin(), a.end(), 2);

    cout << *ret << endl;

    cout << "Array slicing" << endl;

    ArraySlice<int> s = a.slice(1, 2);

    cout << "s[0] = " << s[0] << endl;
    cout << "s[1] = " << s[1] << endl;

    cout << "This should trigger a bounds check error" << endl;

    a[10] = 1;

    return 0;
}

