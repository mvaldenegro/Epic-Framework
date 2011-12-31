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

#ifndef EPIC_CORE_LINKEDLIST
#define	EPIC_CORE_LINKEDLIST

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {
        template<typename T>
        class LinkedList
        {
            private:
                struct Node
                {
                    T data;
                    Node *next;

                    Node(T e, Node *n = nullptr) : data(e), next(n)
                    {
                    }

                    ~Node()
                    {
                        delete next;
                    }
                };

                Node *first;
                Node *last;

            public:

                class Iterator
                {
                    
                };

                LinkedList() : first(nullptr), last(nullptr)
                {
                }

                ~LinkedList()
                {
                    delete first;
                }

                LinkedList<T>& operator=(const LinkedList<T>& other)
                {

                }

                LinkedList<T>& append(T e)
                {
                    if(first == nullptr) {
                        first = new Node(e);
                        last = first;

                    } else {
                        Node *newNode = new Node(e);
                        last->next = newNode;
                        last = newNode;
                    }

                    return *this;
                }

                LinkedList<T>& prepend(T e)
                {
                    Node *newNode = new Node(e, first);
                    first = newNode;

                    return *this;
                }

                int count() const
                {
                    Node *p = first;
                    int ret = 0;

                    while(p != nullptr) {
                        ret++;
                    }

                    return ret;
                }
        };
    };
};

#endif	/* EPIC_CORE_LINKEDLIST */

