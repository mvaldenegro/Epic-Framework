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
                    return this->arrayData->count;
                }

                inline size_t capacity() const
                {
                    return this->arrayData->capacity;
                }

                inline bool isShared() const
                {
                    return this->arrayData.referenceCount() > 1;
                }

                inline bool isEmpty() const
                {
                    return count() == 0;
                }

                T& at(size_t i)
                {
                    return this->arrayData->data[i];
                }

                const T& at(size_t i) const
                {
                    return this->arrayData->data[i];
                }

                T& operator[](size_t i)
                {
                    return this->arrayData->data[i];
                }

                const T& operator[](size_t i) const
                {
                    return this->arrayData->data[i];
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
                    return this->arrayData->data;
                }

                const T* data() const
                {
                    return this->arrayData->data;
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

                        T& operator*()
                        {
                            return array->at(index);
                        }
                    private:
                        size_t index;
                        Array<T> *array;
                };
        };
    }
}

#endif	/* ARRAY_H */

