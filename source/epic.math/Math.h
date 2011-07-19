/* 
 * File:   Math.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 2010, 11:31 PM
 */

#ifndef EPIC_MATH_MATH_H
#define	EPIC_MATH_MATH_H

#include <cmath>

namespace Epic {
    namespace Math {

        template<typename T>
        T squareRoot(T x)
        {
            return std::sqrt(x);
        }

        template<typename T>
        T inverseSquareRoot(T x)
        {
            return 1.0 / squareRoot(x);
        }

        template<typename T, typename Integer>
        Integer floor(T x)
        {
            return static_cast<Integer>(x);
        }

        template<typename T, typename Integer>
        Integer ceiling(T x)
        {
            return floor(x) + 1;
        }

        template<typename T>
        T fractionalPart(T x)
        {
            return x - floor(x);
        }

        template<typename T>
        T absoluteValue(T x)
        {
            return x >= 0.0 ? x : -x;
        }

        template<typename T>
        T clamp(T x, T start, T end)
        {
            if(x < start) {
                return start;
            } else if(x > end) {
                return end;
            } else {
                return x;
            }
        }

        template<typename T>
        T linearInterpolation(T weight, T a, T b)
        {
            return a * weight + (1.0 - weight) * b;
        }

        template<typename T>
        bool fuzzyEquals(T a, T b, T epsilon)
        {
            return absoluteValue(a - b) < epsilon;
        }

        bool fuzzyEquals(float a, float b)
        {
            return fuzzyEquals(a, b, 0.001f);
        }

        bool fuzzyEquals(double a, double b)
        {
            return fuzzyEquals(a, b, 0.00001);
        }
    };
};

#endif	/* EPIC_MATH_MATH_H */

