/*
 * vectorTests.cpp
 *
 *  Created on: 04-12-2011
 *      Author: mvaldenegro
 */

#include <epic.math/Math.h>
#include <epic.math/VectorMath.h>

#include <epic.math/Vector.h>
#include <iostream>

using namespace Epic::Math;
using namespace std;

template<typename T>
void print(const Vector<T>& vector)
{
    cout << "(";

    for(size_t i = 0; i < vector.count(); i++) {
        cout << vector[i]  << ", ";
    }

    cout << " )" << endl;
}

int main(int argc, char **argv)
{
    Vector<float> v(10);
    Vector<float> y(10);
    print(v);

    for(size_t i = 0; i < v.count(); i++) {
        v[i] = float(i);
        y[i] = float(2 * i + 3);
    }

    print(v);
    print(y);

    print(v + y);

    cout << "V's length = " << v.length() << endl;
    cout << "V dot Y = " << Epic::Math::dot(v, y) << endl;

    return 0;
}
