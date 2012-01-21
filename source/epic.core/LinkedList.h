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
                    }
                };

                Node *first;
                Node *last;

            public:
                LinkedList() : first(nullptr), last(nullptr)
                {
                }

                LinkedList(const LinkedList<T>& other) : first(nullptr), last(nullptr)
                {
                    for(LinkedList<T>::ConstIterator it = other.constBegin(); it != other.constEnd(); it++) {
                        append(*it);
                    }
                }

                LinkedList(LinkedList<T>&& other) : first(other.first), last(other.last)
                {
                    other.first = nullptr;
                    other.last = nullptr;
                }

                ~LinkedList()
                {
                    clear();
                }

                LinkedList<T>& operator=(const LinkedList<T>& other)
                {
                    clear();

                    for(LinkedList<T>::ConstIterator it = other.constBegin(); it != other.constEnd(); it++) {
                        append(*it);
                    }

                    return *this;
                }

                size_t count() const
                {
                    size_t ret = 0;

                    for(LinkedList<T>::ConstIterator it = constBegin(); it != constEnd(); it++) {
                        ret++;
                    }

                    return ret;
                }

                bool isEmpty() const
                {
                    return first == nullptr;
                }

                LinkedList<T>& append(const T& e)
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

                LinkedList<T>& operator<<(const T& e)
                {
                    append(e);

                    return *this;
                }

                LinkedList<T>& prepend(T e)
                {
                    Node *newNode = new Node(e, first);
                    first = newNode;

                    return *this;
                }

                void clear()
                {
                    for(Iterator it = begin(); it != end();) {
                        it = remove(it);
                    }

                    first = nullptr;
                    last = nullptr;
                }

                class Iterator
                {
                    friend class LinkedList<T>;

                    public:
                        /* STL compatibility. */
                        typedef std::forward_iterator_tag  iterator_category;
                        typedef T value_type;
                        typedef size_t difference_type;
                        typedef T& reference;
                        typedef T* pointer;

                        Iterator(Node *node)
                        : currentNode(node)
                        {
                        }

                        Iterator(Iterator&& other)
                        : currentNode(other.currentNode)
                        {
                            other.currentNode = nullptr;
                        }

                        Iterator(const Iterator& other)
                        : currentNode(other.currentNode)
                        {
                        }

                        Iterator& operator=(const Iterator& other)
                        {
                            currentNode = other.currentNode;

                            return *this;
                        }

                        bool operator==(const Iterator& other) const
                        {
                            return currentNode == other.currentNode;
                        }

                        bool operator!=(const Iterator& other) const
                        {
                            return currentNode != other.currentNode;
                        }

                        Iterator operator+(int i) const
                        {
                            Node *ret = currentNode;

                            for(int j = 0; (j < i) && (ret != nullptr); j++) {
                                ret = ret->next;
                            }

                            return Iterator(ret);
                        }

                        Iterator& operator++()
                        {
                            currentNode = currentNode->next;

                            return *this;
                        }

                        Iterator operator++(int)
                        {
                            Iterator ret(*this);

                            if(currentNode != nullptr) {
                                currentNode = currentNode->next;
                            }

                            return ret;
                        }

                        Iterator& operator+=(int i)
                        {
                            for(int j = 0; (j < i) && (currentNode != nullptr); j++) {
                                currentNode = currentNode->next;
                            }

                            return *this;
                        }

                        T& operator*()
                        {
                            return currentNode->data;
                        }

                        const T& operator*() const
                        {
                            return currentNode->data;
                        }

                        T* operator->()
                        {
                            return &(currentNode->data);
                        }

                        const T* operator->() const
                        {
                            return &(currentNode->data);
                        }

                    private:
                        Node *currentNode;
                };

                typedef Iterator iterator;

                Iterator begin()
                {
                    return Iterator(first);
                }

                Iterator end()
                {
                    return Iterator(nullptr);
                }

                Iterator remove(Iterator it)
                {
                    Node *previous = nullptr;
                    Node *current = first;

                    while(current != it.currentNode) {
                        previous = current;
                        current = current->next;
                    }

                    if(previous == nullptr) {
                        first = current->next;
                    } else {
                        previous->next = current->next;
                    }

                    if((previous != nullptr) && (previous->next == nullptr)) {
                        last = previous;
                    }

                    delete current;

                    if(previous == nullptr) {
                        return Iterator(first);
                    } else {
                        return Iterator(previous);
                    }
                }

                bool remove(const T& e)
                {
                    bool removed = false;

                    for(Iterator it = begin(); it != end();) {

                        if(*it == e) {

                            it = remove(it);
                            removed = true;

                        } else {

                            it++;
                        }
                    }

                    return removed;
                }

                class ConstIterator
                {
                    friend class LinkedList<T>;

                    public:
                        /* STL compatibility. */
                        typedef std::forward_iterator_tag  iterator_category;
                        typedef T value_type;
                        typedef size_t difference_type;
                        typedef T& reference;
                        typedef T* pointer;

                        ConstIterator(Node *node)
                        : currentNode(node)
                        {
                        }

                        ConstIterator(ConstIterator&& other)
                        : currentNode(other.currentNode)
                        {
                            other.currentNode = nullptr;
                        }

                        ConstIterator(const ConstIterator& other)
                        : currentNode(other.currentNode)
                        {
                        }

                        ConstIterator& operator=(const ConstIterator& other)
                        {
                            currentNode = other.currentNode;

                            return *this;
                        }

                        bool operator==(const ConstIterator& other) const
                        {
                            return currentNode == other.currentNode;
                        }

                        bool operator!=(const ConstIterator& other) const
                        {
                            return currentNode != other.currentNode;
                        }

                        ConstIterator operator+(int i) const
                        {
                            Node *ret = currentNode;

                            for(int j = 0; (j < i) && (ret != nullptr); j++) {
                                ret = ret->next;
                            }

                            return ConstIterator(ret);
                        }

                        ConstIterator& operator++()
                        {
                            currentNode = currentNode->next;

                            return *this;
                        }

                        ConstIterator operator++(int)
                        {
                            ConstIterator ret(*this);

                            currentNode = currentNode->next;

                            return ret;
                        }

                        ConstIterator& operator+=(int i)
                        {
                            for(int j = 0; (j < i) && (currentNode != nullptr); j++) {
                                currentNode = currentNode->next;
                            }

                            return *this;
                        }

                        const T& operator*() const
                        {
                            return currentNode->data;
                        }

                        const T* operator->() const
                        {
                            return &(currentNode->data);
                        }

                    private:
                        Node *currentNode;
                };

                typedef ConstIterator const_iterator;

                ConstIterator constBegin() const
                {
                    return ConstIterator(first);
                }

                ConstIterator constEnd() const
                {
                    return ConstIterator(nullptr);
                }

        };
    }
}

#endif	/* EPIC_CORE_LINKEDLIST */

