/* 
 * File:   Algorithms.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 2010, 05:29 PM
 */

#ifndef ALGORITHMS_H
#define	ALGORITHMS_H

#include <epic.core/Core.h>
#include <epic.core/Array.h>

namespace Epic {
    namespace Core {
        template<typename T>
        T min(const T& a, const T& b)
        {
            return a < b ? a : b;
        }

        template<typename T>
        T max(const T& a, const T& b)
        {
            return a < b ? b : a;
        }

        template<typename T>
        void copyMemory(T *destiny, const T* source, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                destiny[i] = source[i];
            }
        }

        template<typename T>
        void fillMemory(T *destiny, const T& constData, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                destiny[i] = constData;
            }
        }

        template<typename T, typename Function>
        Array<T> map(const Array<T>& input, Function f)
        {
            Array<T> ret;

            for(int i = 0; i < input.size(); i++) {
                ret[i] f(input[i]);
            }

            return ret;
        }
    }
}

#endif	/* ALGORITHMS_H */

