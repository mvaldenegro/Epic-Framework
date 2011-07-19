/*
 * File:   Vector3.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 3010, 11:43 PM
 */

#ifndef EPIC_MATH_VECTOR3_H
#define	EPIC_MATH_VECTOR3_H

#include <iostream>

#include <epic.core/Core.h>
#include <epic.math/Math.h>

namespace Epic {
    namespace Math {

        /*! Two dimensional mathematical vector.
         */
        template<typename Scalar>
        class Vector3
        {
            public:
                /*! Default constructor.
                 *
                 * Initializes the components of this vector to the default value of the scalar type.
                 */
                Vector3()
                {
                    setX(Scalar());
                    setY(Scalar());
                    setZ(Scalar());
                }

                /*! Constructor.
                 *
                 * Constructs a vector from one scalar value, replicating it to each component.
                 */
                Vector3(Scalar value)
                {
                    setX(value);
                    setY(value);
                    setZ(value);
                }

                /*! Constructor.
                 *
                 * Constructs a vector from two scalar values, x and y. z is set to Scalar().
                 */
                Vector3(Scalar x, Scalar y)
                {
                    setX(x);
                    setY(y);
                    setZ(Scalar());
                }

                /*! Constructor.
                 *
                 * Constructs a vector from three scalar values x, y and z.
                 */
                Vector3(Scalar x, Scalar y, Scalar z)
                {
                    setX(x);
                    setY(y);
                    setZ(z);
                }

                /*! Constructor.
                 *
                 * Constructs a vector and assign it's components from a three element array.
                 */
                Vector3(Scalar array[3])
                {
                    setX(array[0]);
                    setY(array[1]);
                    setZ(array[2]);
                }

                /*! Copy constructor.
                 *
                 * Constructs a vector from another two dimension vector.
                 */
                Vector3(const Vector3<Scalar>& other)
                {
                    setX(other.x());
                    setY(other.y());
                    setZ(other.z());
                }

                /*! Destructor.
                 */
                ~Vector3()
                {
                }

                /*! Assignment operator.
                 */
                Vector3<Scalar>& operator=(const Vector3<Scalar>& other)
                {
                    if(this != &other) {
                        setX(other.x());
                        setY(other.y());
                        setZ(other.z());
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

                /*! Returns the z component of this vector.
                 */
                Scalar z() const
                {
                    return mData[2];
                }

                /*! Sets the z component of this vector.
                 */
                void setZ(Scalar z)
                {
                    mData[2] = z;
                }

                /*! Returns the x and y components of this vector.
                 */
                Vector3<Scalar> xy() const
                {
                    return Vector3<Scalar>(*this);
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
                Vector3<Scalar> yx() const
                {
                    return Vector3<Scalar>(y(), x());
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
                    EPIC_ASSERT(i == 1 || i == 2 || i == 3);

                    switch(i) {
                        case 0: {
                            return x();
                        }
                        case 1: {
                            return y();
                        }
                        case 2: {
                            return z();
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
                    EPIC_HARD_ASSERT(i == 1 || i == 2 || i == 3);

                    switch(i) {
                        case 0: {
                            return mData[0];
                        }
                        case 1: {
                            return mData[1];
                        }
                        case 2: {
                            return mData[2];
                        }
                    }
                }

                /*! Equality operator.
                 *
                 * Returns true if all components of @a other are equal to the components of this vector.
                 */
                bool operator==(const Vector3<Scalar>& other) const
                {
                    return x() == other.x() && y() == other.y() && z() == other.z();
                }

                /*! No equality operator.
                 *
                 * Returns true if all components of @a other are not equal to the components of this vector.
                 */
                bool operator!=(const Vector3<Scalar>& other) const
                {
                    return x() != other.x() || y() != other.y() || z() != other.z();
                }

                /*! Fuzzy equality.
                 *
                 *  Performs a comparison using Math::fuzzyEquals instead of exact comparison.
                 */
                bool fuzzyEquals(const Vector3<Scalar>& other, Scalar epsilon) const
                {
                    return Math::fuzzyEquals(x(), other.x(), epsilon) &&
                           Math::fuzzyEquals(y(), other.y(), epsilon) &&
                           Math::fuzzyEquals(z(), other.z(), epsilon) ;
                }

                /*! Fuzzy no equality.
                 *
                 *  Performs a comparison using Math::fuzzyEquals instead of exact comparison.
                 */
                bool fuzzyNotEquals(const Vector3<Scalar>& other, Scalar epsilon) const
                {
                    return !fuzzyEquals(other, epsilon);
                }

                /*! Negation operator.
                 *
                 * Returns a Vector3 with the negated components (changed sign) of this vector.
                 */
                Vector3<Scalar> operator-() const
                {
                    return Vector3<Scalar>(-x(), -y(), -z());
                }

                /*! Addition operator.
                 *
                 * Performs component-wise addition.
                 */
                Vector3<Scalar> operator+(const Vector3<Scalar>& other) const
                {
                    return Vector3<Scalar>(x() + other.x(),
                                           y() + other.y(),
                                           z() + other.z());
                }

                /*! Substraction operator.
                 *
                 * Performs component-wise difference.
                 */
                Vector3<Scalar> operator-(const Vector3<Scalar>& other) const
                {
                    return Vector3<Scalar>(x() - other.x(),
                                           y() - other.y(),
                                           z() - other.z());
                }

                /*! Product operator
                 *
                 * Performs component-wise product.
                 */
                Vector3<Scalar> operator*(const Vector3<Scalar>& other) const
                {
                    return Vector3<Scalar>(x() * other.x(),
                                           y() * other.y(),
                                           z() * other.z());
                }

                /*! Division operator.
                 *
                 * Performs component-wise division.
                 */
                Vector3<Scalar> operator/(const Vector3<Scalar>& other) const
                {
                    return Vector3<Scalar>(x() / other.x(),
                                           y() / other.y(),
                                           z() / other.z());
                }

                /*! Scalar addition operator.
                 *
                 * Adds @a f to all components of this vector and returns the result.
                 */
                Vector3<Scalar> operator+(Scalar f) const
                {
                    return Vector3<Scalar>(x() + f, y() + f, z() + f);
                }

                /*! Scalar substraction operator.
                 *
                 * Substracts @a f from all components of this vector and returns the result.
                 */
                Vector3<Scalar> operator-(Scalar f) const
                {
                    return Vector3<Scalar>(x() - f, y() - f, z() - f);
                }

                /*! Scalar product operator.
                 *
                 * Multiplies @a f with all components of this vector and returns the result.
                 */
                Vector3<Scalar> operator*(Scalar f) const
                {
                    return Vector3<Scalar>(f * x(), f * y(), f * z());
                }

                /*! Scalar division operator.
                 *
                 * Divides all components of this vector by @a f and returns the result.
                */
                Vector3<Scalar> operator/(Scalar f) const
                {
                    return Vector3<Scalar>(x() / f, y() / f, z() / f);
                }

                /*! Returns the square of the length of this vector.
                 */
                Scalar lengthSquared() const
                {
                    return x() * x() + y() * y() + z() * z();
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
                    setZ(z() / len);
                }

                /*! Returns the normalized version of this vector.
                 */
                Vector3<Scalar> normalized() const
                {
                    return (*this) / length();
                }

            private:
                Scalar mData[3];
        };

        /*! Scalar addition operator.
         *
         * Adds @a f to all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector3<Scalar> operator+(Scalar f, const Vector3<Scalar>& v)
        {
            return v + f;
        }

        /*! Scalar substraction operator.
         *
         * Substracts @a f from all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector3<Scalar> operator-(Scalar f, const Vector3<Scalar>& v)
        {
            return Vector3<Scalar>(f - v.x(), f - v.y(), f - v.z());
        }

        /*! Scalar product operator.
         *
         * Multiplies @a f with all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector3<Scalar> operator*(Scalar f, const Vector3<Scalar>& v)
        {
            return v * f;
        }

        /*! Scalar division operator.
         *
         * Divides all components of this vector by @a f and returns the result.
         */
        template<typename Scalar>
        Vector3<Scalar> operator/(Scalar f, const Vector3<Scalar>& v)
        {
            return Vector3<Scalar>(f / v.x(), f / v.y(), f / v.z());
        }

        template<typename Scalar>
        std::ostream& operator<<(std::ostream& stream, const Vector3<Scalar>& v)
        {
            return stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
        }

        /*! Single precision floating point 3D vector.
         */
        typedef Vector3<float> Vector3F;

        /*! Double precision floating point 3D vector.
         */
        typedef Vector3<double> Vector3D;

        /*! Signed byte 3D vector.
         */
        typedef Vector3<Epic::Core::SByte> Vector3B;

        /*! Unsigned byte 3D vector.
         */
        typedef Vector3<Epic::Core::Byte> Vector3UB;

        /*! Signed short 3D vector.
         */
        typedef Vector3<Epic::Core::Int16> Vector3S;

        /*! Unsigned short 3D vector.
         */
        typedef Vector3<Epic::Core::UInt16> Vector3US;

        /*! Signed integer 3D vector.
         */
        typedef Vector3<Epic::Core::Int32> Vector3I;

        /*! Unsigned integer 3D vector.
         */
        typedef Vector3<Epic::Core::UInt32> Vector3UI;

        /*! Signed long 3D vector.
         */
        typedef Vector3<Epic::Core::Int64> Vector3L;

        /*! Unsigned long 3D vector.
         */
        typedef Vector3<Epic::Core::UInt64> Vector3UL;
    };
};

#endif	/* EPIC_MATH_VECTOR3_H */

