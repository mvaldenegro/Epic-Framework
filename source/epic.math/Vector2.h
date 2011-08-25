/*
 * File:   Vector2.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 2010, 11:43 PM
 */

#ifndef EPIC_MATH_VECTOR2_H
#define	EPIC_MATH_VECTOR2_H

#include <iostream>

#include <epic.core/Core.h>
#include <epic.math/Math.h>

namespace Epic {
    namespace Math {

        /*! Two dimensional mathematical vector.
         */
        template<typename Scalar>
        class Vector2
        {
            public:
                /*! Default constructor.
                 *
                 * Initializes the components of this vector to the default value of the scalar type.
                 */
                Vector2()
                {
                    setX(Scalar());
                    setY(Scalar());
                }

                /*! Constructor.
                 *
                 * Constructs a vector from one scalar value, replicating it to each component.
                 */
                Vector2(Scalar value)
                {
                    setX(value);
                    setY(value);
                }

                /*! Constructor.
                 *
                 * Constructs a vector from two scalar values, x and y.
                 */
                Vector2(Scalar x, Scalar y)
                {
                    setX(x);
                    setY(y);
                }

                /*! Constructor.
                 *
                 * Constructs a vector and assign it's components from a two element array.
                 */
                Vector2(Scalar array[2])
                {
                    setX(array[0]);
                    setY(array[1]);
                }

                /*! Copy constructor.
                 *
                 * Constructs a vector from another two dimension vector.
                 */
                Vector2(const Vector2<Scalar>& other)
                {
                    setX(other.x());
                    setY(other.y());
                }

                /*! Destructor.
                 */
                ~Vector2()
                {
                }

                /*! Assignment operator.
                 */
                Vector2<Scalar>& operator=(const Vector2<Scalar>& other)
                {
                    if(this != &other) {
                        setX(other.x());
                        setY(other.y());
                    }

                    return *this;
                }

                /*! Returns the x component of this vector.
                 */
                Scalar x() const
                {
                    return mData[0];
                }

                /*! Sets the x component of this vector.
                 */
                void setX(Scalar x)
                {
                    mData[0] = x;
                }

                /*! Returns the y component of this vector.
                 */
                Scalar y() const
                {
                    return mData[1];
                }

                /*! Sets the y component of this vector.
                 */
                void setY(Scalar y)
                {
                    mData[1] = y;
                }

                /*! Returns the x and y components of this vector.
                 */
                Vector2<Scalar> xy() const
                {
                    return Vector2<Scalar>(*this);
                }

                /*! Sets the x and y components of this vector.
                 */
                void setXY(Scalar x, Scalar y)
                {
                    setX(x);
                    setY(y);
                }

                /*! Returns the swizzled y and x components of this vector.
                 */
                Vector2<Scalar> yx() const
                {
                    return Vector2<Scalar>(y(), x());
                }

                /*! Returns a pointer to the internal data array.
                 */
                Scalar *data()
                {
                    return mData;
                }

                /*! Returns a pointer to the internal data array.
                 */
                const Scalar *data() const
                {
                    return mData;
                }

                /*! Array operator.
                 *
                 * Allows indexing into the vector, possible index values are 0 for the x component,
                 * and 1 for the y component.
                 */
                Scalar operator[](int i) const
                {
                    EPIC_ASSERT(i == 1 || i == 2);

                    switch(i) {
                        case 0: {
                            return x();
                        }
                        case 1: {
                            return y();
                        }

                        default: {
                            return Scalar();
                        }
                    }
                }

                /*! Array operator.
                 *
                 * Allows indexing into the vector, possible index values are 0 for the x component,
                 * and 1 for the y component.
                 *
                 * This overload returns a reference, so it can be used to assign values in the vector.
                 */
                Scalar& operator[](int i)
                {
                    EPIC_HARD_ASSERT(i == 1 || i == 2);

                    switch(i) {
                        case 0: {
                            return mData[0];
                        }
                        case 1: {
                            return mData[1];
                        }
                    }
                }

                /*! Equality operator.
                 *
                 * Returns true if all components of @a other are equal to the components of this vector.
                 */
                bool operator==(const Vector2<Scalar>& other) const
                {
                    return x() == other.x() && y() == other.y();
                }

                /*! No equality operator.
                 *
                 * Returns true if all components of @a other are not equal to the components of this vector.
                 */
                bool operator!=(const Vector2<Scalar>& other) const
                {
                    return x() != other.x() || y() != other.y();
                }

                /*! Fuzzy equality.
                 *
                 *  Performs a comparison using Math::fuzzyEquals instead of exact comparison.
                 */
                bool fuzzyEquals(const Vector2<Scalar>& other, Scalar epsilon) const
                {
                    return Epic::Math::fuzzyEquals(x(), other.x(), epsilon) &&
                           Epic::Math::fuzzyEquals(y(), other.y(), epsilon);
                }

                /*! Fuzzy no equality.
                 *
                 *  Performs a comparison using Math::fuzzyEquals instead of exact comparison.
                 */
                bool fuzzyNotEquals(const Vector2<Scalar>& other, Scalar epsilon) const
                {
                    return !fuzzyEquals(other, epsilon);
                }

                /*! Negation operator.
                 *
                 * Returns a Vector2 with the negated components (changed sign) of this vector.
                 */
                Vector2<Scalar> operator-() const
                {
                    return Vector2<Scalar>(-x(), -y());
                }

                /*! Addition operator.
                 *
                 * Performs component-wise addition.
                 */
                Vector2<Scalar> operator+(const Vector2<Scalar>& other) const
                {
                    return Vector2<Scalar>(x() + other.x(),
                                           y() + other.y());
                }

                /*! Substraction operator.
                 *
                 * Performs component-wise difference.
                 */
                Vector2<Scalar> operator-(const Vector2<Scalar>& other) const
                {
                    return Vector2<Scalar>(x() - other.x(),
                                           y() - other.y());
                }

                /*! Product operator
                 *
                 * Performs component-wise product.
                 */
                Vector2<Scalar> operator*(const Vector2<Scalar>& other) const
                {
                    return Vector2<Scalar>(x() * other.x(),
                                           y() * other.y());
                }

                /*! Division operator.
                 *
                 * Performs component-wise division.
                 */
                Vector2<Scalar> operator/(const Vector2<Scalar>& other) const
                {
                    return Vector2<Scalar>(x() / other.x(),
                                           y() / other.y());
                }

                /*! Scalar addition operator.
                 *
                 * Adds @a f to all components of this vector and returns the result.
                 */
                Vector2<Scalar> operator+(Scalar f) const
                {
                    return Vector2<Scalar>(x() + f, y() + f);
                }

                /*! Scalar substraction operator.
                 *
                 * Substracts @a f from all components of this vector and returns the result.
                 */
                Vector2<Scalar> operator-(Scalar f) const
                {
                    return Vector2<Scalar>(x() - f, y() - f);
                }

                /*! Scalar product operator.
                 *
                 * Multiplies @a f with all components of this vector and returns the result.
                 */
                Vector2<Scalar> operator*(Scalar f) const
                {
                    return Vector2<Scalar>(f * x(), f * y());
                }

                /*! Scalar division operator.
                 *
                 * Divides all components of this vector by @a f and returns the result.
                */
                Vector2<Scalar> operator/(Scalar f) const
                {
                    return Vector2<Scalar>(x() / f, y() / f);
                }

                /*! Returns the square of the length of this vector.
                 */
                Scalar lengthSquared() const
                {
                    return x() * x() + y() * y();
                }

                /*! Returns the length of this vector.
                 */
                Scalar length() const
                {
                    return Math::squareRoot(lengthSquared());
                }

                /*! Normalizes this vector in place.
                 */
                void normalize()
                {
                    Scalar len = length();

                    setX(x() / len);
                    setY(y() / len);
                }

                /*! Returns the normalized version of this vector.
                 */
                Vector2<Scalar> normalized() const
                {
                    return (*this) / length();
                }

            private:
                Scalar mData[2];
        };

        /*! Scalar addition operator.
         *
         * Adds @a f to all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector2<Scalar> operator+(Scalar f, const Vector2<Scalar>& v)
        {
            return v + f;
        }

        /*! Scalar substraction operator.
         *
         * Substracts @a f from all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector2<Scalar> operator-(Scalar f, const Vector2<Scalar>& v)
        {
            return Vector2<Scalar>(f - v.x(), f - v.y());
        }

        /*! Scalar product operator.
         *
         * Multiplies @a f with all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector2<Scalar> operator*(Scalar f, const Vector2<Scalar>& v)
        {
            return v * f;
        }

        /*! Scalar division operator.
         *
         * Divides all components of this vector by @a f and returns the result.
         */
        template<typename Scalar>
        Vector2<Scalar> operator/(Scalar f, const Vector2<Scalar>& v)
        {
            return Vector2<Scalar>(f / v.x(), f / v.y());
        }

        template<typename Scalar>
        std::ostream& operator<<(std::ostream& stream, const Vector2<Scalar>& v)
        {
            return stream << "(" << v.x() << ", " << v.y() << ")";
        }

        /*! Single precision floating point 2D vector.
         */
        typedef Vector2<float> Vector2F;

        /*! Double precision floating point 2D vector.
         */
        typedef Vector2<double> Vector2D;

        /*! Signed byte 2D vector.
         */
        typedef Vector2<Epic::Core::SByte> Vector2B;

        /*! Unsigned byte 2D vector.
         */
        typedef Vector2<Epic::Core::Byte> Vector2UB;

        /*! Signed short 2D vector.
         */
        typedef Vector2<Epic::Core::Int16> Vector2S;

        /*! Unsigned short 2D vector.
         */
        typedef Vector2<Epic::Core::UInt16> Vector2US;

        /*! Signed integer 2D vector.
         */
        typedef Vector2<Epic::Core::Int32> Vector2I;

        /*! Unsigned integer 2D vector.
         */
        typedef Vector2<Epic::Core::UInt32> Vector2UI;

        /*! Signed long 2D vector.
         */
        typedef Vector2<Epic::Core::Int64> Vector2L;

        /*! Unsigned long 2D vector.
         */
        typedef Vector2<Epic::Core::UInt64> Vector2UL;
    }
}

#endif	/* EPIC_MATH_VECTOR2_H */

