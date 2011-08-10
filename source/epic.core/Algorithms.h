/*
 * File:   Algorithms.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 2010, 05:29 PM
 */

#ifndef ALGORITHMS_H
#define	ALGORITHMS_H

#include <epic.core/Core.h>

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
        bool memoryEquals(const T *a, const T *b, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }

            return true;
        }

        template<typename T>
        void fillMemory(T *destiny, const T& constData, size_t size)
        {
            for(size_t i = 0; i < size; i++) {
                destiny[i] = constData;
            }
        }
    }
}

#endif	/* ALGORITHMS_H */

