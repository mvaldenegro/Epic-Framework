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

#ifndef EPIC_MATH_MATRIX2_H_
#define EPIC_MATH_MATRIX2_H_

#include <epic.core/Core.h>
#include <epic.math/Vector2.h>

namespace Epic {
    namespace Math {
        template<typename Scalar>
        class Matrix2
        {
            public:
                Matrix2()
                : matrixData()
                {
                }

                Matrix2(Scalar diagonal)
                : matrixData()
                {
                    setDiagonal(diagonal);
                }

                Matrix2(Scalar m00, Scalar m11)
                : matrixData()
                {
                    at(0, 0) = m00;
                    at(1, 1) = m11;
                }

                Matrix2(Scalar m00, Scalar m01, Scalar m10, Scalar m11)
                : matrixData()
                {
                    at(0, 0) = m00;
                    at(0, 1) = m01;
                    at(1, 0) = m10;
                    at(1, 1) = m11;
                }

                Matrix2(const Matrix2<Scalar>& other)
                : matrixData()
                {
                    at(0, 0) = other.at(0, 0);
                    at(0, 1) = other.at(0, 1);
                    at(1, 0) = other.at(1, 0);
                    at(1, 1) = other.at(1, 1);
                }

                Matrix2(Matrix2<Scalar>&& other)
                : matrixData()
                {
                    at(0, 0) = other.at(0, 0);
                    at(0, 1) = other.at(0, 1);
                    at(1, 0) = other.at(1, 0);
                    at(1, 1) = other.at(1, 1);
                }

                ~Matrix2()
                {
                }

                size_t rows() const
                {
                    return 2;
                }

                size_t columns() const
                {
                    return 2;
                }

                void setDiagonal(Scalar diagonal)
                {
                    for(size_t i = 0; i < rows(); i++) {
                        at(i, i) = diagonal;
                    }
                }

                void setDiagonal(Scalar m00, Scalar m11)
                {
                    at(0, 0) = m00;
                    at(1, 1) = m11;
                }

                Scalar& operator()(size_t row, size_t column)
                {
                    return at(row, column);
                }

                const Scalar& operator()(size_t row, size_t column) const
                {
                    return at(row, column);
                }

                Scalar& at(size_t row, size_t column)
                {
                    return matrixData[row + 2 * column];
                }

                const Scalar& at(size_t row, size_t column) const
                {
                    return matrixData[row + 2 * column];
                }

                Scalar* data()
                {
                    return matrixData;
                }

                const Scalar* data() const
                {
                    return matrixData;
                }

                Matrix2<Scalar> transpose() const
                {
                    return Matrix2<Scalar>(at(0, 0), at(1, 0), at(0, 1), at(1, 1));
                }

                Matrix2<Scalar> inverse() const
                {
                    return Matrix2<Scalar>(at(1, 1), -at(0, 1), -at(1, 0), at(0, 0)) / determinant();
                }

                Scalar determinant() const
                {
                    return at(0, 0) * at(1, 1) - at(1, 0) * at(0, 1);
                }

                Matrix2<Scalar> operator+(const Matrix2<Scalar>& other) const
                {
                    return Matrix2<Scalar>(at(0, 0) + other.at(0, 0),
                                      at(0, 1) + other.at(0, 1),
                                      at(1, 0) + other.at(1, 0),
                                      at(1, 1) + other.at(1, 1));
                }

                Matrix2<Scalar> operator-(const Matrix2<Scalar>& other) const
                {
                    return Matrix2<Scalar>(at(0, 0) - other.at(0, 0),
                                      at(0, 1) - other.at(0, 1),
                                      at(1, 0) - other.at(1, 0),
                                      at(1, 1) - other.at(1, 1));
                }

                Matrix2<Scalar> operator*(const Matrix2<Scalar>& other) const
                {
                    Matrix2<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            for(size_t k = 0; k < rows(); k++) {
                                ret.at(i, j) += at(i, k) * other.at(k, j);
                            }
                        }
                    }

                    return ret;
                }

                Matrix2<Scalar> operator*(Scalar x) const
                {
                    return Matrix2<Scalar>(at(0, 0) * x,
                                      at(0, 1) * x,
                                      at(1, 0) * x,
                                      at(1, 1) * x);
                }

                Matrix2<Scalar> operator/(Scalar x) const
                {
                    return Matrix2<Scalar>(at(0, 0) / x,
                                      at(0, 1) / x,
                                      at(1, 0) / x,
                                      at(1, 1) / x);
                }

                Vector2<Scalar> operator*(const Vector2<Scalar>& v) const
                {
                    return Vector2<Scalar>(v.x() * at(0, 0) + v.y() * at(0, 1),
                                           v.x() * at(1, 0) + v.y() * at(1, 1));
                }

            private:
                Scalar matrixData[2 * 2];
        };

        template<typename Scalar>
        Matrix2<Scalar> operator*(Scalar x, const Matrix2<Scalar>& a)
        {
            return a * x;
        }

        typedef Matrix2<float> Matrix2F;
        typedef Matrix2<double> Matrix2D;
    }
}


#endif /* EPIC_MATH_MATRIX2_H_ */
