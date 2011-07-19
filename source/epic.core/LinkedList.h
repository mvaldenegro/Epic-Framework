/* 
 * File:   LinkedList.h
 * Author: mvaldenegro
 *
 * Created on 17 de abril de 2011, 02:28 AM
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

