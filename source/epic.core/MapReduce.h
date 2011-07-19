/* 
 * File:   MapReduce.h
 * Author: mvaldenegro
 *
 * Created on 10 de junio de 2011, 03:34 PM
 */

#ifndef EPIC_CORE_MAPREDUCE_H
#define	EPIC_CORE_MAPREDUCE_H

#include <epic.core/Array.h>

namespace Epic {
    namespace Core {

        template<typename T, typename Function>
        Array<T> map(const Array<T>& input, Function f)
        {
            Array<T> ret;

            for(int i = 0; i < input.count(); i++) {
                ret[i] f(input[i]);
            }

            return ret;
        }
    }
}


#endif	/* EPIC_CORE_MAPREDUCE_H */

