/*
 * Matrix4.h
 *
 *  Created on: 26-08-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_MATH_MATRIX4_H_
#define EPIC_MATH_MATRIX4_H_

#include <epic.core/Core.h>
#include <epic.math/Vector4.h>

namespace Epic {
    namespace Math {
        template<typename Scalar>
        class Matrix4
        {
            public:
                Matrix4()
                : matrixData()
                {

                }

                Matrix4(Scalar diagonal)
                : matrixData()
                {
                    setDiagonal(diagonal);
                }

                Matrix4(Scalar m00, Scalar m11, Scalar m22, Scalar m33)
                : matrixData()
                {
                    at(0, 0) = m00;
                    at(1, 1) = m11;
                    at(2, 2) = m22;
                    at(3, 3) = m33;
                }

                Matrix4(Scalar m00, Scalar m01, Scalar m02, Scalar m03,
                        Scalar m10, Scalar m11, Scalar m12, Scalar m13,
                        Scalar m20, Scalar m21, Scalar m22, Scalar m23,
                        Scalar m30, Scalar m31, Scalar m32, Scalar m33)
                : matrixData()
                {
                    at(0, 0) = m00;
                    at(0, 1) = m01;
                    at(0, 2) = m02;
                    at(0, 3) = m03;
                    at(1, 0) = m10;
                    at(1, 1) = m11;
                    at(1, 2) = m12;
                    at(1, 3) = m13;
                    at(2, 0) = m20;
                    at(2, 1) = m21;
                    at(2, 2) = m22;
                    at(2, 3) = m23;
                    at(3, 0) = m30;
                    at(3, 1) = m31;
                    at(3, 2) = m32;
                    at(3, 3) = m33;
                }

                Matrix4(const Matrix4<Scalar>& other)
                : matrixData()
                {
                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            at(i, j) = other.at(i, j);
                        }
                    }
                }

                Matrix4(Matrix4<Scalar>&& other)
                : matrixData()
                {
                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            at(i, j) = other.at(i, j);
                        }
                    }
                }

                ~Matrix4()
                {
                }

                size_t rows() const
                {
                    return 4;
                }

                size_t columns() const
                {
                    return 4;
                }

                void setDiagonal(Scalar diagonal)
                {
                    for(size_t i = 0; i < rows(); i++) {
                        at(i, i) = diagonal;
                    }
                }

                void setDiagonal(Scalar m00, Scalar m11, Scalar m22, Scalar m33)
                {
                    at(0, 0) = m00;
                    at(1, 1) = m11;
                    at(2, 2) = m22;
                    at(3, 3) = m33;
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
                    return matrixData[row + 4 * column];
                }

                const Scalar& at(size_t row, size_t column) const
                {
                    return matrixData[row + 4 * column];
                }

                Scalar* data()
                {
                    return matrixData;
                }

                const Scalar* data() const
                {
                    return matrixData;
                }

                Matrix4<Scalar> transpose() const
                {
                    Matrix4<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(j, i);
                        }
                    }

                    return ret;
                }

                Matrix4<Scalar> inverse() const
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

                    return Matrix4<Scalar>(e * k - f * h, f * g - d * k, d * h - e * g,
                                           c * h - b * k, a * k - c * g, g * b - a * h,
                                           b * f - c * e, c * d - a * f, a * e - b * d).transpose() / determinant();
                }

                Scalar determinant() const
                {
                    Scalar m00 = at(0, 0);
                    Scalar m01 = at(0, 1);
                    Scalar m02 = at(0, 2);
                    Scalar m03 = at(0, 3);

                    Scalar m10 = at(1, 0);
                    Scalar m11 = at(1, 1);
                    Scalar m12 = at(1, 2);
                    Scalar m13 = at(1, 3);

                    Scalar m20 = at(2, 0);
                    Scalar m21 = at(2, 1);
                    Scalar m22 = at(2, 2);
                    Scalar m23 = at(2, 3);

                    Scalar m30 = at(3, 0);
                    Scalar m31 = at(3, 1);
                    Scalar m32 = at(3, 2);
                    Scalar m33 = at(3, 3);

                    return m03 * m12 * m21 * m30 - m02 * m13 * m21 * m30 - m03 * m11 * m22 * m30 + m01 * m13 * m22 * m30 +
                           m02 * m11 * m23 * m30 - m01 * m12 * m23 * m30 - m03 * m12 * m20 * m31 + m02 * m13 * m20 * m31 +
                           m03 * m10 * m22 * m31 - m00 * m13 * m22 * m31 - m02 * m10 * m23 * m31 + m00 * m12 * m23 * m31 +
                           m03 * m11 * m20 * m32 - m01 * m13 * m20 * m32 - m03 * m10 * m21 * m32 + m00 * m13 * m21 * m32 +
                           m01 * m10 * m23 * m32 - m00 * m11 * m23 * m32 - m02 * m11 * m20 * m33 + m01 * m12 * m20 * m33 +
                           m02 * m10 * m21 * m33 - m00 * m12 * m21 * m33 - m01 * m10 * m22 * m33 + m00 * m11 * m22 * m33;
                }

                Matrix4<Scalar> operator+(const Matrix4<Scalar>& other) const
                {
                    Matrix4<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) + other.at(i, j);
                        }
                    }

                    return ret;
                }

                Matrix4<Scalar> operator-(const Matrix4<Scalar>& other) const
                {
                    Matrix4<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) - other.at(i, j);
                        }
                    }

                    return ret;
                }

                Matrix4<Scalar> operator*(const Matrix4<Scalar>& other) const
                {
                    Matrix4<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            for(size_t k = 0; k < rows(); k++) {
                                ret.at(i, j) += at(i, k) * other.at(k, j);
                            }
                        }
                    }

                    return ret;
                }

                Matrix4<Scalar> operator*(Scalar x) const
                {
                    Matrix4<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) * x;
                        }
                    }

                    return ret;
                }

                Matrix4<Scalar> operator/(Scalar x) const
                {
                    Matrix4<Scalar> ret;

                    for(size_t i = 0; i < rows(); i++) {
                        for(size_t j = 0; j < columns(); j++) {
                            ret.at(i, j) = at(i, j) / x;
                        }
                    }

                    return ret;
                }

                Vector4<Scalar> operator*(const Vector4<Scalar>& v) const
                {
                    return Vector4<Scalar>(v.x() * at(0, 0) + v.y() * at(0, 1) + v.z() * at(0, 2) + v.w() * at(0, 3),
                                           v.x() * at(1, 0) + v.y() * at(1, 1) + v.z() * at(1, 2) + v.w() * at(1, 3),
                                           v.x() * at(2, 0) + v.y() * at(2, 1) + v.z() * at(2, 2) + v.w() * at(2, 3),
                                           v.x() * at(3, 0) + v.y() * at(3, 1) + v.z() * at(3, 2) + v.w() * at(3, 3));
                }

            private:
                Scalar matrixData[4 * 4];
        };

        template<typename Scalar>
        Matrix4<Scalar> operator*(Scalar x, const Matrix4<Scalar>& a)
        {
            return a * x;
        }

        typedef Matrix4<float> Matrix4F;
        typedef Matrix4<double> Matrix4D;
    }
}


#endif /* EPIC_MATH_MATRIX4_H_ */
