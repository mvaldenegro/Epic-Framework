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
                ret << f(input[i]);
            }

            return ret;
        }
    }
}


#endif	/* EPIC_CORE_MAPREDUCE_H */

