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

#ifndef EPIC_MATH_VECTORMATH_H
#define	EPIC_MATH_VECTORMATH_H

#include <epic.math/Vector2.h>
#include <epic.math/Vector3.h>
#include <epic.math/Vector4.h>

#include <epic.math/Vector.h>

namespace Epic {
    namespace Math {

        template<typename T>
        T dot(const Vector2<T>& a, const Vector2<T>& b)
        {
            return a.x() * b.x() + a.y() + b.y();
        }

        template<typename T>
        T dot(const Vector3<T>& a, const Vector3<T>& b)
        {
            return a.x() * b.x() + a.y() + b.y() + a.z() * b.z();
        }

        template<typename T>
        T dot(const Vector4<T>& a, const Vector4<T>& b)
        {
            return a.x() * b.x() + a.y() + b.y() + a.z() * b.z() + a.w() * b.w();
        }

        template<typename Scalar>
        Scalar dot(const Vector<Scalar>& a, const Vector<Scalar>& b)
        {
            EPIC_HARD_ASSERT(a.count() == b.count());
            Scalar ret = Scalar(0.0);

            for(size_t i = 0; i < a.count(); i++) {
                ret += a(i) * b(i);
            }

            return ret;
        }

        template<typename T>
        Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b)
        {
            return Vector3<T>(a.y() * b.z() - a.z() * b.y(),
                              a.z() * b.x() - a.x() * b.z(),
                              a.x() * b.y() - a.y() * b.x());
        }

        template<typename T>
        T distance(const Vector2<T>& a, const Vector2<T>& b)
        {
            Vector2<T> tmp = a - b;

            return squareRoot(dot(tmp, tmp));
        }

        template<typename T>
        T distance(const Vector3<T>& a, const Vector3<T>& b)
        {
            Vector3<T> tmp = a - b;

            return squareRoot(dot(tmp, tmp));
        }

        template<typename T>
        T distance(const Vector4<T>& a, const Vector4<T>& b)
        {
            Vector4<T> tmp = a - b;

            return squareRoot(dot(tmp, tmp));
        }

        Vector2<float> reflect(const Vector2<float> &incident, const Vector2<float>& normal)
        {
            return incident - 2.0f * normal * dot(normal, incident);
        }

        Vector3<float> reflect(const Vector3<float> &incident, const Vector3<float>& normal)
        {
            return incident - 2.0f * normal * dot(normal, incident);
        }

        Vector4<float> reflect(const Vector4<float> &incident, const Vector4<float>& normal)
        {
            return incident - 2.0f * normal * dot(normal, incident);
        }

        Vector2<double> reflect(const Vector2<double> &incident, const Vector2<double>& normal)
        {
            return incident - 2.0 * normal * dot(normal, incident);
        }

        Vector3<double> reflect(const Vector3<double> &incident, const Vector3<double>& normal)
        {
            return incident - 2.0 * normal * dot(normal, incident);
        }

        Vector4<double> reflect(const Vector4<double> &incident, const Vector4<double>& normal)
        {
            return incident - 2.0 * normal * dot(normal, incident);
        }
    }
}

#endif	/* EPIC_MATH_VECTORMATH_H */

