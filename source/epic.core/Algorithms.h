/* 
 * File:   Algorithms.h
 * Author: hunts
 *
 * Created on 13 de noviembre de 2010, 05:29 PM
 */

#ifndef ALGORITHMS_H
#define	ALGORITHMS_H

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
    }
}

#endif	/* ALGORITHMS_H */

