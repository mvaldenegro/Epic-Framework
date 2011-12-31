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

#ifndef EPIC_MATH_MATRIX_H_
#define EPIC_MATH_MATRIX_H_

#include <epic.core/Core.h>
#include <epic.core/Algorithms.h>

namespace Epic {
    namespace Math {

        template<typename Scalar>
        class Matrix
        {
            public:
                Matrix(size_t rows, size_t columns, Scalar value = Scalar())
                : matrixRows(rows), matrixColumns(columns), matrixData(new Scalar[rows * columns])
                {
                    Epic::Core::fillMemory(matrixData, value, rows * columns);
                }

                Matrix(const Matrix<Scalar>& other)
                : matrixRows(other.rows()), matrixColumns(other.columns()),
                  matrixData(new Scalar[other.rows() * other.columns()])
                {
                    Epic::Core::copyMemory(matrixData, other.matrixData, other.rows() * other.columns());
                }

                Matrix(Matrix<Scalar>&& other)
                : matrixRows(other.rows()), matrixColumns(other.columns()), matrixData(other.matrixData)
                {
                    other.matrixData = nullptr;
                }

                ~Matrix()
                {
                    delete [] matrixData;
                }

                size_t rows() const
                {
                    return matrixRows;
                }

                size_t columns() const
                {
                    return matrixColumns;
                }

                Matrix& operator=(const Matrix<Scalar>& other)
                {
                    if(this != &other) {
                        matrixRows = other.rows();
                        matrixColumns = other.columns();
                        matrixData = new Scalar(rows() * columns());

                        Epic::Core::copyMemory(matrixData, other.matrixData, rows() * columns());
                    }

                    return *this;
                }

                Scalar& operator()(size_t row, size_t column)
                {
                    return at(row, column);
                }

                const Scalar& operator()(size_t row, size_t column) const
                {
                    return at(row, column);
                }

                Scalar& at(int row, int column)
                {
                    return matrixData[column + row * matrixColumns];
                }

                const Scalar& at(int row, int column) const
                {
                    return matrixData[column + row * matrixColumns];
                }

                Scalar* data()
                {
                    return matrixData;
                }

                const Scalar* data() const
                {
                    return matrixData;
                }

                Matrix<Scalar> operator+(const Matrix<Scalar>& other) const
                {
                    EPIC_HARD_ASSERT((other.rows() == rows()) && (other.columns() == columns()));

                    Matrix<Scalar> ret(rows(), columns());

                    for(size_t row = 0; row < rows(); row++) {
                        for(size_t column = 0; column < columns(); column++) {
                            ret.at(row, column) = at(row, column) + other.at(row, column);
                        }
                    }

                    return ret;
                }

                Matrix<Scalar> operator-(const Matrix<Scalar>& other) const
                {
                    EPIC_HARD_ASSERT((other.rows() == rows()) && (other.columns() == columns()));

                    Matrix<Scalar> ret(rows(), columns());

                    for(size_t row = 0; row < rows(); row++) {
                        for(size_t column = 0; column < columns(); column++) {
                            ret.at(row, column) = at(row, column) - other.at(row, column);
                        }
                    }

                    return ret;
                }

                Matrix<Scalar> operator*(const Matrix<Scalar>& other) const
                {
                    EPIC_HARD_ASSERT(columns() == other.rows());

                    Matrix<Scalar> ret(rows(), other.columns());

                    for(size_t row = 0; row < rows(); row++) {
                        for(size_t column = 0; column < columns(); column++) {

                            Scalar sum = 0.0;

                            for(size_t idx = 0; idx < columns(); idx++) {
                                sum += at(row, idx) * other.at(idx, column);
                            }

                            ret.at(row, column) = sum;
                        }
                    }

                    return ret;
                }

                Matrix<Scalar> operator*(Scalar x) const
                {
                    Matrix<Scalar> ret(rows(), columns());

                    for(size_t row = 0; row < rows(); row++) {
                        for(size_t column = 0; column < columns(); column++) {
                            ret.at(row, column) = at(row, column) * x;
                        }
                    }

                    return ret;
                }

                Matrix<Scalar> operator/(Scalar x) const
                {
                    Matrix<Scalar> ret(rows(), columns());

                    for(size_t row = 0; row < rows(); row++) {
                        for(size_t column = 0; column < columns(); column++) {
                            ret.at(row, column) = at(row, column) / x;
                        }
                    }

                    return ret;
                }
/*
                Vector2<Scalar> operator*(const Vector2<Scalar>& v) const
                {
                    return Vector2<Scalar>(v.x() * at(0, 0) + v.y() * at(0, 1),
                                           v.x() * at(1, 0) + v.y() * at(1, 1));
                }
*/
                static Matrix<Scalar> identity(size_t size)
                {
                    Matrix<Scalar> ret(size, size);

                    for(size_t i = 0; i < size; i++) {
                        ret.at(i, i) = Scalar(1.0);
                    }

                    return ret;
                }

            private:
                size_t matrixRows;
                size_t matrixColumns;
                Scalar *matrixData;
        };

        typedef Matrix<float> MatrixF;
        typedef Matrix<double> MatrixD;

    } /* namespace Math */
} /* namespace Epic */
#endif /* EPIC_MATH_MATRIX_H_ */
