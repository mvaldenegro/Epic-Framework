/*
 * File:   Array.h
 * Author: hunts
 *
 * Created on 30 de enero de 2011, 01:34 AM
 */

#ifndef EPIC_CORE_ARRAY_H
#define	EPIC_CORE_ARRAY_H

#include <epic.core/Core.h>
#include <epic.core/Algorithms.h>
#include <epic.core/SharedPointer.h>

namespace Epic {
    namespace Core {

        /*! Array container.
         *
         * This class represents an Array.
         */

        template<typename T>
        class Array
        {
            private:

                struct ArrayInternalData
                {
                    public:
                        ArrayInternalData(T *data, int count, int capacity)
                        {
                            this->data = data;
                            this->count = count;
                            this->capacity = capacity;
                        }
                        
                        ~ArrayInternalData()
                        {
                            delete [] data;
                        }

                        T *data;
                        size_t count;
                        size_t capacity;
                };

                SharedPointer<ArrayInternalData> arrayData;

            public:

                /*! Constructor.
                 */
                Array() : arrayData(new ArrayInternalData(nullptr, 0, 0))
                {
                }

                /*! Constructor. Initializes this array instance by copying the data from a c-style array.
                 */
                Array(const T* carray, size_t len) : arrayData(new ArrayInternalData(new T[len], len, len))
                {
                    copyMemory(this->arrayData->data, carray, this->arrayData->count);
                }

                /*! Constructor. Initializes this array instance by copying the data from another array.
                 */
                Array(const Array<T>& other) : arrayData(other.arrayData)
                {
                }

                /*! Destructor.
                 */
                ~Array()
                {
                }

                /*! Assignment operator.
                 */
                Array<T>& operator=(const Array<T>& other)
                {
                    if(this != &other) {
                        arrayData = other.arrayData;
                    }

                    return *this;
                }

                inline size_t count() const
                {
                    if(arrayData.isNull()) {
                        return 0;
                    }

                    return this->arrayData->count;
                }

                inline size_t capacity() const
                {
                    if(arrayData.isNull()) {
                        return 0;
                    }

                    return this->arrayData->capacity;
                }

                inline bool isShared() const
                {
                    return arrayData.isShared();
                }

                inline bool isEmpty() const
                {
                    return arrayData.isNull() || (count() == 0);
                }

                T& at(size_t i)
                {
                    detach();
                    
                    return this->arrayData->data[i];
                }

                const T& at(size_t i) const
                {   
                    return this->arrayData->data[i];
                }

                T& operator[](size_t i)
                {
                    return at(i);
                }

                const T& operator[](size_t i) const
                {
                    return at(i);
                }

                bool operator==(const Array<T>& other) const
                {
                    if(count() == other.count()) {

                        for(size_t i = 0; i < count(); i++) {
                            if(!(other.at(i) == this->at(i))) {
                                return false;
                            }
                        }

                        return true;
                    }

                    return false;
                }

                bool operator!=(const Array<T>& other) const
                {
                    return !(*this == other);
                }

                void reserve(size_t size)
                {
                    detach();
                    
                    if(size > this->arrayData->capacity) {
                        T *newArray = new T[size];

                        copyMemory(newArray, this->arrayData->data, count());

                        delete [] this->arrayData->data;
                        this->arrayData->data = newArray;

                        this->arrayData->capacity = size;
                    }
                }

                void resize(size_t desiredSize)
                {
                    reserve(2 * desiredSize);
                }

                void append(const T& e)
                {
                    detach();
                    resize(count() + 1);

                    this->arrayData->data[count()] = e;
                    this->arrayData->count++;
                }

                Array<T>& operator<<(const T& e)
                {
                    append(e);

                    return *this;
                }

                T* data()
                {
                    if(arrayData.isNull()) {
                        return nullptr;
                    }
                    
                    detach();

                    return this->arrayData->data;
                }

                const T* data() const
                {
                    if(arrayData.isNull()) {
                        return nullptr;
                    }

                    return this->arrayData->data;
                }

                bool contains(const T& e) const
                {
                    for(size_t i = 0; i < count(); i++) {
                        if(at(i) == e) {
                            return true;
                        }
                    }

                    return false;
                }
                
                void detach()
                {
                    if(!arrayData.isShared()) {
                        return;
                    }
                    
                    T *newData = new T[capacity()];
                    copyMemory(newData, this->arrayData->data, count());
                    
                    size_t cnt = count();
                    size_t cap = capacity();
                    
                    arrayData.detach();
                    arrayData = new ArrayInternalData(newData, cnt, cap);
                }

                static Array<T> wrap(T *array, size_t len)
                {
                    Array<T> ret;

                    ret.arrayData = SharedPointer<ArrayInternalData>(new ArrayInternalData(array, len, len));

                    return ret;
                }

                /* Iterator API */

                class Iterator
                {
                    public:
                        Iterator(Array<T> *a, size_t idx = 0)
                        : index(idx), array(a)
                        {
                        }

                        Iterator(Iterator&& other)
                        : index(other.index), array(other.array)
                        {
                            other.index = 0;
                            other.array = nullptr;
                        }

                        Iterator(const Iterator& other)
                        : index(other.index), array(other.array)
                        {
                        }

                        Iterator& operator=(const Iterator& other)
                        {
                            index = other.index;
                            array = other.array;

                            return *this;
                        }

                        bool operator==(const Iterator& other) const
                        {
                            return (array == other.array) && (index == other.index);
                        }

                        bool operator!=(const Iterator& other) const
                        {
                            return (array == other.array) && (index != other.index);
                        }

                        bool operator<(const Iterator& other) const
                        {
                            return (array == other.array) && (index < other.index);
                        }

                        bool operator<=(const Iterator& other) const
                        {
                            return (array == other.array) && (index <= other.index);
                        }

                        bool operator>(const Iterator& other) const
                        {
                            return (array == other.array) && (index > other.index);
                        }

                        bool operator>=(const Iterator& other) const
                        {
                            return (array == other.array) && (index >= other.index);
                        }

                        Iterator operator+(int i) const
                        {
                            return Iterator(array, index + i);
                        }

                        Iterator& operator++()
                        {
                            index++;

                            return *this;
                        }

                        Iterator operator++(int)
                        {
                            Iterator ret(*this);

                            index++;

                            return ret;
                        }

                        Iterator& operator+=(int i)
                        {
                            index += i;

                            return *this;
                        }

                        Iterator operator-(int i) const
                        {
                            return Iterator(array, index - i);
                        }

                        Iterator& operator--()
                        {
                            index--;

                            return *this;
                        }

                        Iterator operator--(int)
                        {
                            Iterator ret(*this);

                            index--;

                            return ret;
                        }

                        Iterator& operator-=(int i)
                        {
                            index -= i;

                            return *this;
                        }

                        T& operator*()
                        {
                            return array->at(index);
                        }

                        const T& operator*() const
                        {
                            return array->at(index);
                        }

                        T* operator->()
                        {
                            return array->data() + index;
                        }

                        const T* operator->() const
                        {
                            return array->data() + index;
                        }

                    private:
                        size_t index;
                        Array<T> *array;
                };

                Iterator begin()
                {
                    return Iterator(this);
                }

                Iterator end()
                {
                    return Iterator(this, count());
                }

                class ConstIterator
                {
                    public:
                        ConstIterator(const Array<T> *a, size_t idx = 0)
                        : index(idx), array(a)
                        {
                        }

                        ConstIterator(ConstIterator&& other)
                        : index(other.index), array(other.array)
                        {
                            other.index = 0;
                            other.array = nullptr;
                        }

                        ConstIterator(const ConstIterator& other)
                        : index(other.index), array(other.array)
                        {
                        }

                        ConstIterator& operator=(const ConstIterator& other)
                        {
                            index = other.index;
                            array = other.array;

                            return *this;
                        }

                        bool operator==(const ConstIterator& other) const
                        {
                            return (array == other.array) && (index == other.index);
                        }

                        bool operator!=(const ConstIterator& other) const
                        {
                            return (array == other.array) && (index != other.index);
                        }

                        bool operator<(const ConstIterator& other) const
                        {
                            return (array == other.array) && (index < other.index);
                        }

                        bool operator<=(const ConstIterator& other) const
                        {
                            return (array == other.array) && (index <= other.index);
                        }

                        bool operator>(const ConstIterator& other) const
                        {
                            return (array == other.array) && (index > other.index);
                        }

                        bool operator>=(const ConstIterator& other) const
                        {
                            return (array == other.array) && (index >= other.index);
                        }

                        ConstIterator operator+(int i) const
                        {
                            return ConstIterator(array, index + i);
                        }

                        ConstIterator& operator++()
                        {
                            index++;

                            return *this;
                        }

                        ConstIterator operator++(int)
                        {
                            ConstIterator ret(*this);

                            index++;

                            return ret;
                        }

                        ConstIterator& operator+=(int i)
                        {
                            index += i;

                            return *this;
                        }

                        ConstIterator operator-(int i) const
                        {
                            return Iterator(array, index - i);
                        }

                        ConstIterator& operator--()
                        {
                            index--;

                            return *this;
                        }

                        ConstIterator operator--(int)
                        {
                            Iterator ret(*this);

                            index--;

                            return ret;
                        }

                        ConstIterator& operator-=(int i)
                        {
                            index -= i;

                            return *this;
                        }

                        const T& operator*() const
                        {
                            return array->at(index);
                        }

                        const T* operator->() const
                        {
                            return array->data() + index;
                        }

                    private:
                        size_t index;
                        const Array<T> *array;
                };

                ConstIterator begin() const
                {
                    return ConstIterator(this);
                }

                ConstIterator end() const
                {
                    return ConstIterator(this, count());
                }

                ConstIterator constBegin() const
                {
                    return ConstIterator(this);
                }

                ConstIterator constEnd() const
                {
                    return ConstIterator(this, count());
                }
        };
    }
}

#endif	/* ARRAY_H */

