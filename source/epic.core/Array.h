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
                        int count;
                        int capacity;
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
                Array(const T* carray, int len) : arrayData(new T[len], len, len)
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
                    for(size_t i = 0; i < count(); i++) {
                        if(other.at(i) != this->at(i)) {
                            return false;
                        }
                    }
                    
                    return true;
                }
                
                bool operator!=(const Array<T>& other) const
                {
                    for(size_t i = 0; i < count(); i++) {
                        if(other.at(i) != this->at(i)) {
                            return true;
                        }
                    }
                    
                    return false;
                }
                                
                void resize(size_t desiredSize)
                {
                    if(desiredSize > this->arrayData->capacity) {
                        T *newArray = new T[2 * desiredSize];
                        
                        copyMemory(newArray, this->arrayData->data, count());
                        
                        delete [] this->arrayData->data;
                        this->arrayData->data = newArray;
                        
                        this->arrayData->capacity = 2 * desiredSize;
                    }
                }
                
                void append(const T& e)
                {
                    resize(count() + 1);
                    
                    this->arrayData->data[count()] = e;
                    this->arrayData->count++;
                }
                
                T* data()
                {
                    return this->arrayData->data;
                }
                
                const T* data() const
                {
                    return this->arrayData->data;
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
                        int index;
                        Array<T> *array;
                };
        };
    }
}

#endif	/* ARRAY_H */

