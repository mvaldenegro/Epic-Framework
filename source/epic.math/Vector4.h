/*
 * File:   Vector4.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 4010, 11:33 PM
 */

#ifndef EPIC_MATH_VECTOR4_H
#define	EPIC_MATH_VECTOR4_H

#include <iostream>

#include <epic.core/Core.h>
#include <epic.math/Math.h>

namespace Epic {
    namespace Math {

        /*! Two dimensional mathematical vector.
         */
        template<typename Scalar>
        class Vector4
        {
            public:
                /*! Default constructor.
                 *
                 * Initializes the components of this vector to the default value of the scalar type.
                 */
                Vector4()
                {
                    setX(Scalar());
                    setY(Scalar());
                    setZ(Scalar());
                    setW(Scalar());
                }

                /*! Constructor.
                 *
                 * Constructs a vector from one scalar value, replicating it to each component.
                 */
                Vector4(Scalar value)
                {
                    setX(value);
                    setY(value);
                    setZ(value);
                    setW(value);
                }

                /*! Constructor.
                 *
                 * Constructs a vector from two scalar values, x and y. z is set to Scalar().
                 */
                Vector4(Scalar x, Scalar y)
                {
                    setX(x);
                    setY(y);
                    setZ(Scalar());
                    setW(Scalar());
                }

                /*! Constructor.
                 *
                 * Constructs a vector from three scalar values x, y and z.
                 */
                Vector4(Scalar x, Scalar y, Scalar z)
                {
                    setX(x);
                    setY(y);
                    setZ(z);
                    setW(Scalar());
                }

                /*! Constructor.
                 *
                 * Constructs a vector from four scalar values x, y, z and w.
                 */
                Vector4(Scalar x, Scalar y, Scalar z, Scalar w)
                {
                    setX(x);
                    setY(y);
                    setZ(z);
                    setW(w);
                }

                /*! Constructor.
                 *
                 * Constructs a vector and assign it's components from a four element array.
                 */
                Vector4(Scalar array[4])
                {
                    setX(array[0]);
                    setY(array[1]);
                    setZ(array[2]);
                    setW(array[3]);
                }

                /*! Copy constructor.
                 *
                 * Constructs a vector from another two dimension vector.
                 */
                Vector4(const Vector4<Scalar>& other)
                {
                    setX(other.x());
                    setY(other.y());
                    setZ(other.z());
                    setW(other.w());
                }

                /*! Destructor.
                 */
                ~Vector4()
                {
                }

                /*! Assignment operator.
                 */
                Vector4<Scalar>& operator=(const Vector4<Scalar>& other)
                {
                    if(this != &other) {
                        setX(other.x());
                        setY(other.y());
                        setZ(other.z());
                        setW(other.w());
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

                /*! Returns the z component of this vector.
                 */
                Scalar w() const
                {
                    return mData[3];
                }

                /*! Sets the z component of this vector.
                 */
                void setW(Scalar w)
                {
                    mData[3] = w;
                }

                /*! Returns the x and y components of this vector.
                 */
                Vector4<Scalar> xy() const
                {
                    return Vector4<Scalar>(*this);
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
                Vector4<Scalar> yx() const
                {
                    return Vector4<Scalar>(y(), x());
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
                        case 3: {
                            return w();
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
                    EPIC_HARD_ASSERT(i == 1 || i == 2 || i == 4);

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
                        case 3: {
                            return mData[3];
                        }
                    }
                }

                /*! Equality operator.
                 *
                 * Returns true if all components of @a other are equal to the components of this vector.
                 */
                bool operator==(const Vector4<Scalar>& other) const
                {
                    return x() == other.x() &&
                           y() == other.y() &&
                           z() == other.z() &&
                           w() == other.w();
                }

                /*! No equality operator.
                 *
                 * Returns true if all components of @a other are not equal to the components of this vector.
                 */
                bool operator!=(const Vector4<Scalar>& other) const
                {
                    return x() != other.x() ||
                           y() != other.y() ||
                           z() != other.z() ||
                           w() != other.w();
                }

                /*! Fuzzy equality.
                 *
                 *  Performs a comparison using Math::fuzzyEquals instead of exact comparison.
                 */
                bool fuzzyEquals(const Vector4<Scalar>& other, Scalar epsilon) const
                {
                    return Math::fuzzyEquals(x(), other.x(), epsilon) &&
                           Math::fuzzyEquals(y(), other.y(), epsilon) &&
                           Math::fuzzyEquals(z(), other.z(), epsilon) &&
                           Math::fuzzyEquals(w(), other.w(), epsilon);
                }

                /*! Fuzzy no equality.
                 *
                 *  Performs a comparison using Math::fuzzyEquals instead of exact comparison.
                 */
                bool fuzzyNotEquals(const Vector4<Scalar>& other, Scalar epsilon) const
                {
                    return !fuzzyEquals(other, epsilon);
                }

                /*! Negation operator.
                 *
                 * Returns a Vector4 with the negated components (changed sign) of this vector.
                 */
                Vector4<Scalar> operator-() const
                {
                    return Vector4<Scalar>(-x(), -y(), -z(), -w());
                }

                /*! Addition operator.
                 *
                 * Performs component-wise addition.
                 */
                Vector4<Scalar> operator+(const Vector4<Scalar>& other) const
                {
                    return Vector4<Scalar>(x() + other.x(),
                                           y() + other.y(),
                                           z() + other.z(),
                                           w() + other.w());
                }

                /*! Substraction operator.
                 *
                 * Performs component-wise difference.
                 */
                Vector4<Scalar> operator-(const Vector4<Scalar>& other) const
                {
                    return Vector4<Scalar>(x() - other.x(),
                                           y() - other.y(),
                                           z() - other.z()
                                           w() - other.w());
                }

                /*! Product operator
                 *
                 * Performs component-wise product.
                 */
                Vector4<Scalar> operator*(const Vector4<Scalar>& other) const
                {
                    return Vector4<Scalar>(x() * other.x(),
                                           y() * other.y(),
                                           z() * other.z(),
                                           w() * other.w());
                }

                /*! Division operator.
                 *
                 * Performs component-wise division.
                 */
                Vector4<Scalar> operator/(const Vector4<Scalar>& other) const
                {
                    return Vector4<Scalar>(x() / other.x(),
                                           y() / other.y(),
                                           z() / other.z(),
                                           w() / other.w());
                }

                /*! Scalar addition operator.
                 *
                 * Adds @a f to all components of this vector and returns the result.
                 */
                Vector4<Scalar> operator+(Scalar f) const
                {
                    return Vector4<Scalar>(x() + f, y() + f, z() + f, w() + f);
                }

                /*! Scalar substraction operator.
                 *
                 * Substracts @a f from all components of this vector and returns the result.
                 */
                Vector4<Scalar> operator-(Scalar f) const
                {
                    return Vector4<Scalar>(x() - f, y() - f, z() - f, w() - f);
                }

                /*! Scalar product operator.
                 *
                 * Multiplies @a f with all components of this vector and returns the result.
                 */
                Vector4<Scalar> operator*(Scalar f) const
                {
                    return Vector4<Scalar>(f * x(), f * y(), f * z(), f * w());
                }

                /*! Scalar division operator.
                 *
                 * Divides all components of this vector by @a f and returns the result.
                */
                Vector4<Scalar> operator/(Scalar f) const
                {
                    return Vector4<Scalar>(x() / f, y() / f, z() / f, w() / f);
                }

                /*! Returns the square of the length of this vector.
                 */
                Scalar lengthSquared() const
                {
                    return x() * x() + y() * y() + z() * z() + w() * w();
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
                    setW(w() / len);
                }

                /*! Returns the normalized version of this vector.
                 */
                Vector4<Scalar> normalized() const
                {
                    return (*this) / length();
                }

            private:
                Scalar mData[4];
        };

        /*! Scalar addition operator.
         *
         * Adds @a f to all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector4<Scalar> operator+(Scalar f, const Vector4<Scalar>& v)
        {
            return v + f;
        }

        /*! Scalar substraction operator.
         *
         * Substracts @a f from all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector4<Scalar> operator-(Scalar f, const Vector4<Scalar>& v)
        {
            return Vector4<Scalar>(f - v.x(), f - v.y(), f - v.z(), f - v.w());
        }

        /*! Scalar product operator.
         *
         * Multiplies @a f with all components of this vector and returns the result.
         */
        template<typename Scalar>
        Vector4<Scalar> operator*(Scalar f, const Vector4<Scalar>& v)
        {
            return v * f;
        }

        /*! Scalar division operator.
         *
         * Divides all components of this vector by @a f and returns the result.
         */
        template<typename Scalar>
        Vector4<Scalar> operator/(Scalar f, const Vector4<Scalar>& v)
        {
            return Vector4<Scalar>(f / v.x(), f / v.y(), f / v.z(), f / v.w());
        }

        template<typename Scalar>
        std::ostream& operator<<(std::ostream& stream, const Vector4<Scalar>& v)
        {
            return stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << "," << v.w() << ")";
        }

        /*! Single precision floating point 4D vector.
         */
        typedef Vector4<float> Vector4F;

        /*! Double precision floating point 4D vector.
         */
        typedef Vector4<double> Vector4D;

        /*! Signed byte 4D vector.
         */
        typedef Vector4<Epic::Core::SByte> Vector4B;

        /*! Unsigned byte 4D vector.
         */
        typedef Vector4<Epic::Core::Byte> Vector4UB;

        /*! Signed short 4D vector.
         */
        typedef Vector4<Epic::Core::Int16> Vector4S;

        /*! Unsigned short 4D vector.
         */
        typedef Vector4<Epic::Core::UInt16> Vector4US;

        /*! Signed integer 4D vector.
         */
        typedef Vector4<Epic::Core::Int32> Vector4I;

        /*! Unsigned integer 4D vector.
         */
        typedef Vector4<Epic::Core::UInt32> Vector4UI;

        /*! Signed long 4D vector.
         */
        typedef Vector4<Epic::Core::Int64> Vector4L;

        /*! Unsigned long 4D vector.
         */
        typedef Vector4<Epic::Core::UInt64> Vector4UL;
    }
}

#endif	/* EPIC_MATH_VECTOR4_H */


