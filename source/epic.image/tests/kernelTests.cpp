/*
 * kernelTests.cpp
 *
 *  Created on: 03-12-2011
 *      Author: mvaldenegro
 */

#include <epic.math/Matrix.h>
#include <epic.image/processing/Kernel.h>

#include <iostream>

using namespace Epic::Math;
using namespace Epic::Image::Processing;
using namespace std;

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

void print(const MatrixD& matrix)
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
    MatrixD gauss = Kernel::gaussian(7, 0.84 * 0.84);

    print(gauss);

    return 0;
}
