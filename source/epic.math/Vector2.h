/* 
 * File:   Vector2.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 2010, 11:43 PM
 */

#ifndef EPIC_MATH_VECTOR2_H
#define	EPIC_MATH_VECTOR2_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Math {
        template<typename T>
        class Vector2<T>
        {
            public:
                Vector2()
                {
                    setX(T())
                    setY(T());
                }

                Vector2(T value)
                {
                    setX(value);
                    setY(value);
                }

                Vector2(T x, T y)
                {
                    setX(x);
                    setY(y);
                }

                Vector2(T array[2])
                {
                    setX(array[0]);
                    setY(array[1]);
                }

                Vector2(const Vector2<T>& other)
                {
                    setX(other.x());
                    setY(other.y());
                }

                ~Vector2()
                {
                }

                Vector2<T>& operator=(const Vector2<T>& other)
                {
                    if(this != &other) {
                        setX(other.x());
                        setY(other.y());
                    }

                    return *this;
                }

                T x() const
                {
                    return data[0];
                }

                void setX(T x)
                {
                    data[0] = x;
                }

                T y() const
                {
                    return data[1];
                }

                void setY(T y)
                {
                    data[1] = y;
                }

                Vector2<T> xy() const
                {
                    return Vector2<T>(*this);
                }

                void setXY(T x, T y)
                {
                    setX(x);
                    setY(y);
                }

                Vector2<T> yx() const
                {
                    return Vector2<T>(y(), x());
                }

                T operator[](int i) const
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
                            return T();
                        }
                    }
                }

                T& operator[](int i)
                {
                    EPIC_HARD_ASSERT(i == 1 || i == 2);

                    switch(i) {
                        case 0: {
                            return data[0];
                        }
                        case 1: {
                            return data[1];
                        }
                    }
                }

            private:
                T data[2];
        };

        typedef Vector2<float> Vector2F;
        typedef Vector2<double> Vector2D;

        typedef Vector2<Epic::Core::SByte> Vector2B;
        typedef Vector2<Epic::Core::Byte> Vector2UB;

        typedef Vector2<Epic::Core::Int16> Vector2S;
        typedef Vector2<Epic::Core::UInt16> Vector2US;

        typedef Vector2<Epic::Core::Int32> Vector2I;
        typedef Vector2<Epic::Core::UInt32> Vector2UI;

        typedef Vector2<Epic::Core::Int64> Vector2L;
        typedef Vector2<Epic::Core::UInt64> Vector2UL;
    };
};

#endif	/* EPIC_MATH_VECTOR2_H */

