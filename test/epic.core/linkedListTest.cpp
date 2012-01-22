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
#include <algorithm>
#include <epic.core/LinkedList.h>

using namespace std;
using Epic::Core::LinkedList;

int main(int argc, char **argv)
{
    LinkedList<int> l;

    l.append(0);
    l.append(1);
    l.append(2);

    for(LinkedList<int>::Iterator it = l.begin(); it != l.end(); it++) {
        cout << "Numero: " << *it << endl;
    }

    l.clear();

    l.append(6);
    l.append(7);
    l.append(8);

    for(LinkedList<int>::ConstIterator it = l.constBegin(); it != l.constEnd(); it++) {
        cout << "Numero v2: " << *it << endl;
    }

    LinkedList<int>::Iterator ret = std::find(l.begin(), l.end(), 8);

    cout << *ret << endl;

    ret = l.remove(ret);

    cout << *ret << endl;

    for(LinkedList<int>::ConstIterator it = l.constBegin(); it != l.constEnd(); it++) {
        cout << "Numero v2: " << *it << endl;
    }

    l.append(9);

    for(LinkedList<int>::ConstIterator it = l.constBegin(); it != l.constEnd(); it++) {
        cout << "Numero v3: " << *it << endl;
    }

    l.remove(7);
    l.remove(6);

    for(LinkedList<int>::ConstIterator it = l.constBegin(); it != l.constEnd(); it++) {
        cout << "Numero v4: " << *it << endl;
    }

    return 0;
}
