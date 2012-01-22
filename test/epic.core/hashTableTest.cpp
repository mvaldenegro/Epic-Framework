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

#include <iostream>
#include <epic.core/HashTable.h>

using namespace std;
using Epic::Core::HashTable;

int main(int argc, char **argv)
{
    HashTable<int, int> h;

    for(int i = 1; i <= 10; i++) {
        h.insert(i, 10 * i);
    }

    for(int i = 1; i <= 10; i++) {
        cout << "h[" << i << "] = " << h.lookup(i) << endl;
    }

    h[11] = 29;

    for(int i = 1; i <= 11; i++) {
        cout << "h'[" << i << "] = " << h.lookup(i) << endl;
    }

    return 0;
}
