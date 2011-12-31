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

#ifndef EPIC_MATH_VECTOR_H_
#define EPIC_MATH_VECTOR_H_

#include <epic.core/Array.h>
#include <epic.math/Math.h>

namespace Epic {
    namespace Math {
        template<typename Scalar>
        class Vector : public Epic::Core::Array<Scalar>
        {
            public:
                explicit Vector(size_t size) : Epic::Core::Array<Scalar>(size)
                {
                }

                Vector(const Vector<Scalar>& other) : Epic::Core::Array<Scalar>(other)
                {
                }

                Vector(const Epic::Core::Array<Scalar>& other) : Epic::Core::Array<Scalar>(other)
                {
                }

                ~Vector()
                {
                }

                Vector<Scalar>& operator=(const Vector<Scalar>& other)
                {
                    if(this != &other) {
                        *this = static_cast<Epic::Core::Array<Scalar>& >(other);
                    }

                    return *this;
                }

                EPIC_INLINE Scalar length() const
                {
                    return Math::squareRoot(lengthSquared());
                }

                EPIC_INLINE Scalar lengthSquared() const
                {
                    Scalar ret = Scalar();

                    for(size_t i = 0; i < this->count(); i++) {
                        ret += this->at(i) * this->at(i);
                    }

                    return ret;
                }

                Vector<Scalar> operator+(const Vector<Scalar>& other) const
                {
                    EPIC_HARD_ASSERT(this->count() == other.count());

                    Vector<Scalar> ret(this->count());

                    for(size_t i = 0; i < this->count(); i++) {
                        ret.at(i) = this->at(i) + other.at(i);
                    }

                    return ret;
                }

                Vector<Scalar> operator-(const Vector<Scalar>& other) const
                {
                    EPIC_HARD_ASSERT(this->count() == other.count());

                    Vector<Scalar> ret(this->count());

                    for(size_t i = 0; i < this->count(); i++) {
                        ret.at(i) = this->at(i) - other.at(i);
                    }

                    return ret;
                }

                Vector<Scalar> operator*(Scalar value) const
                {
                    Vector<Scalar> ret(this->count());

                    for(size_t i = 0; i < this->count(); i++) {
                        ret.at(i) = value * this->at(i);
                    }

                    return ret;
                }

                Vector<Scalar> operator/(Scalar value) const
                {
                    Vector<Scalar> ret(this->count());

                    for(size_t i = 0; i < this->count(); i++) {
                        ret.at(i) = this->at(i) / value;
                    }

                    return ret;
                }

                Vector<Scalar>& operator+=(const Vector<Scalar>& other)
                {
                    EPIC_HARD_ASSERT(this->count() == other.count());

                    for(size_t i = 0; i < this->count(); i++) {
                        this->at(i) += other.at(i);
                    }

                    return *this;
                }

                Vector<Scalar>& operator-=(const Vector<Scalar>& other)
                {
                    EPIC_HARD_ASSERT(this->count() == other.count());

                    for(size_t i = 0; i < this->count(); i++) {
                        this->at(i) -= other.at(i);
                    }

                    return *this;
                }

                Vector<Scalar>& operator*=(Scalar value)
                {
                    for(size_t i = 0; i < this->count(); i++) {
                        this->at(i) *= value;
                    }

                    return *this;
                }

                Vector<Scalar>& operator/=(Scalar value)
                {
                    for(size_t i = 0; i < this->count(); i++) {
                        this->at(i) /= value;
                    }

                    return *this;
                }
        };

        typedef Vector<float> VectorF;
        typedef Vector<double> VectorD;
    }
}


#endif /* EPIC_MATH_VECTOR_H_ */
