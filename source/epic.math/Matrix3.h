/*
 * Matrix3.h
 *
 *  Created on: 26-08-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_MATH_MATRIX3_H_
#define EPIC_MATH_MATRIX3_H_

#include <epic.core/Core.h>
#include <epic.math/Vector3.h>

namespace Epic {
    namespace Math {
        template<typename Scalar>
        class Matrix3
        {
            public:
                Matrix3()
                : matrixData()
                {

                }

                Matrix3(Scalar diagonal)
                : matrixData()
                {
                    setDiagonal(diagonal);
                }

                Matrix3(Scalar m00, Scalar m11, Scalar m22)
                : matrixData()
                {
                    at(0, 0) = m00;
                    at(1, 1) = m11;
                    at(2, 2) = m22;
                }

                Matrix3(Scalar m00, Scalar m01, Scalar m02,
                        Scalar m10, Scalar m11, Scalar m12,
                        Scalar m20, Scalar m21, Scalar m22)
                : matrixData()
                {
                    at(0, 0) = m00;
                    at(0, 1) = m01;
                    at(0, 2) = m02;
                    at(1, 0) = m10;
                    at(1, 1) = m11;
                    at(1, 2) = m12;
                    at(2, 0) = m20;
                    at(2, 1) = m21;
                    at(2, 2) = m22;
                }

                Matrix3(const Matrix3<Scalar>& other)
                : matrixData()
                {
                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            at(i, j) = other.at(i, j);
                        }
                    }
                }

                Matrix3(Matrix3<Scalar>&& other)
                : matrixData()
                {
                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            at(i, j) = other.at(i, j);
                        }
                    }
                }

                ~Matrix3()
                {
                }

                size_t rows() const
                {
                    return 3;
                }

                size_t columns() const
                {
                    return 3;
                }

                void setDiagonal(Scalar diagonal)
                {
                    for(size_t i = 0; i < rows(); i++) {
                        at(i, i) = diagonal;
                    }
                }

                void setDiagonal(Scalar m00, Scalar m11, Scalar m22)
                {
                    at(0, 0) = m00;
                    at(1, 1) = m11;
                    at(2, 2) = m22;
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
                    return matrixData[row + 3 * column];
                }

                const Scalar& at(size_t row, size_t column) const
                {
                    return matrixData[row + 3 * column];
                }

                Scalar* data()
                {
                    return matrixData;
                }

                const Scalar* data() const
                {
                    return matrixData;
                }

                Matrix3<Scalar> transpose() const
                {
                    Matrix3<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(j, i);
                        }
                    }

                    return ret;
                }

                Matrix3<Scalar> inverse() const
                {
                    Scalar a = at(0, 0);
                    Scalar b = at(0, 1);
                    Scalar c = at(0, 2);

                    Scalar d = at(1, 0);
                    Scalar e = at(1, 1);
                    Scalar f = at(1, 2);

                    Scalar g = at(2, 0);
                    Scalar h = at(2, 1);
                    Scalar k = at(2, 2);

                    return Matrix3<Scalar>(e * k - f * h, f * g - d * k, d * h - e * g,
                                           c * h - b * k, a * k - c * g, g * b - a * h,
                                           b * f - c * e, c * d - a * f, a * e - b * d).transpose() / determinant();
                }

                Scalar determinant() const
                {
                    Scalar a = at(0, 0);
                    Scalar b = at(0, 1);
                    Scalar c = at(0, 2);

                    Scalar d = at(1, 0);
                    Scalar e = at(1, 1);
                    Scalar f = at(1, 2);

                    Scalar g = at(2, 0);
                    Scalar h = at(2, 1);
                    Scalar k = at(2, 2);

                    return a * (e * k - f * h) +
                           b * (f * g - k * d) +
                           c * (d * h - e * g);
                }

                Matrix3<Scalar> operator+(const Matrix3<Scalar>& other) const
                {
                    Matrix3<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) + other.at(i, j);
                        }
                    }

                    return ret;
                }

                Matrix3<Scalar> operator-(const Matrix3<Scalar>& other) const
                {
                    Matrix3<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) - other.at(i, j);
                        }
                    }

                    return ret;
                }

                Matrix3<Scalar> operator*(const Matrix3<Scalar>& other) const
                {
                    Matrix3<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            for(size_t k = 0; k < rows(); k++) {
                                ret.at(i, j) += at(i, k) * other.at(k, j);
                            }
                        }
                    }

                    return ret;
                }

                Matrix3<Scalar> operator*(Scalar x) const
                {
                    Matrix3<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) * x;
                        }
                    }

                    return ret;
                }

                Matrix3<Scalar> operator/(Scalar x) const
                {
                    Matrix3<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) / x;
                        }
                    }

                    return ret;
                }

                Vector3<Scalar> operator*(const Vector3<Scalar>& v) const
                {
                    return Vector3<Scalar>(v.x() * at(0, 0) + v.y() * at(0, 1) + v.z() * at(0, 2),
                                           v.x() * at(1, 0) + v.y() * at(1, 1) + v.z() * at(1, 2),
                                           v.x() * at(2, 0) + v.y() * at(2, 1) + v.z() * at(2, 2));
                }

            private:
                Scalar matrixData[3 * 3];
        };

        template<typename Scalar>
        Matrix3<Scalar> operator*(Scalar x, const Matrix3<Scalar>& a)
        {
            return a * x;
        }

        typedef Matrix3<float> Matrix3F;
        typedef Matrix3<double> Matrix3D;
    }
}


#endif /* EPIC_MATH_MATRIX3_H_ */
