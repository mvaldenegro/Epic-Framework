/*
 * matrixTests.cpp
 *
 *  Created on: 09-11-2011
 *      Author: mvaldenegro
 */

#include <iostream>
using namespace std;

#include <epic.math/Matrix.h>
using namespace Epic::Math;

void print(const MatrixF& matrix)
{


    for(size_t row = 0; row < matrix.rows(); row++) {
        cout << "[";
        for(size_t column = 0; column < matrix.columns(); column++) {
            cout << matrix.at(row, column) << " ";
        }
        cout << "]" << endl;
    }


}

int main(int argc, char **argv)
{
    MatrixF m(3, 3, 2);
    MatrixF identity = MatrixF::identity(3);

    print(m);
    print(identity);
    print(m + identity);
    print(m * (m + identity));

    MatrixF a(2, 3);
    MatrixF b(3, 3);

    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;
    a(1, 0) = 4;
    a(1, 1) = 5;
    a(1, 2) = 6;
    cout << "A = " << endl;
    print(a);

    b(0, 0) = 1;
    b(0, 1) = 2;
    b(0, 2) = 3;
    b(1, 0) = 4;
    b(1, 1) = 5;
    b(1, 2) = 6;
    b(2, 0) = 7;
    b(2, 1) = 8;
    b(2, 2) = 9;
    cout << "B = " << endl;
    print(b);

    cout << "A * B = " << endl;
    print(a * b);

    return 0;
}
