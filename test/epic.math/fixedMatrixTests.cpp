/*
 * matrixTests.cpp
 *
 *  Created on: 24-08-2011
 *      Author: mvaldenegro
 */

#include <epic.math/Matrix2.h>
#include <epic.math/Matrix3.h>
#include <epic.math/Matrix4.h>
#include <epic.math/Math.h>

#include <iostream>

using Epic::Math::Matrix2;
using Epic::Math::Matrix2F;
using Epic::Math::Matrix3;
using Epic::Math::Matrix3F;
using Epic::Math::Vector2;
using Epic::Math::Vector2F;
using namespace std;

template<typename T>
void print(const Matrix2<T>& a)
{
    cout << "( ";

    for(size_t i = 0; i < a.rows(); i++) {
        for(size_t j = 0; j < a.columns(); j++) {
            cout << a(i, j) << " ";
        }
    }

    cout << ")" << endl;
}

template<typename T>
void print(const Matrix3<T>& a)
{
    cout << "( ";

    for(size_t i = 0; i < a.rows(); i++) {
        for(size_t j = 0; j < a.columns(); j++) {
            cout << a(i, j) << " ";
        }
    }

    cout << ")" << endl;
}


template<typename T>
void print(const Vector2<T>& a)
{
    cout << "( " << a.x() << " " << a.y() << " )" << endl;
}


int main(int argc, char **argv)
{
    cout << "Matrix2 tests" << endl;
    Matrix2F zero;
    print(zero);

    Matrix2F identity(1.0);
    print(identity);

    Matrix2F a(1.0, 2.0, 3.0, 4.0);
    print(a);

    cout << "A's transpose" << endl;
    print(a.transpose());
    cout << "A's determinant: " << a.determinant() << endl;
    Matrix2F inverse = a.inverse();
    cout << "A's inverse" << endl;
    print(inverse);

    cout << "A * inverse(A)" << endl;
    print(a * inverse);

    cout << "inverse(A) * A" << endl;
    print(inverse * a);

    print(2.0f * identity);
    print(identity * 2.0f);

    Vector2F v(1.0, 2.0);
    print(v);
    print(identity * v);
    print(a * v);

    cout << "Matrix3 tests" << endl;

    Matrix3F b(1.0, 2.0, 3.0, 5.0, 5.0, 6.0, 7.0, 8.0, 1.0);
    print(a);

    cout << "B's determinant: " << b.determinant() << endl;
    Matrix3F bInverse = b.inverse();
    cout << "B's inverse" << endl;
    print(bInverse);

    cout << "B * inverse(B)" << endl;
    print(b * bInverse);

    cout << "inverse(B) * B" << endl;
    print(bInverse * b);


    return 0;
}
