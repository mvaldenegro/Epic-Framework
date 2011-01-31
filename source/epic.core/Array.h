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
                T *data;
                int length;
                int capacity;

            public:

                /*! Constructor.
                 */
                Array() : data(nullptr), length(0), capacity(0)
                {

                }

                /*! Constructor. Initializes this array instance by copying the data from a c-style array.
                 */
                Array(const T* carray, int len) : data(new T[len]), length(len), capacity(len)
                {
                    copyMemory(this->data, carray, this->length);
                }

                /*! Constructor. Initializes this array instance by copying the data from another array.
                 */
                Array(const Array<T>& other) : data(new T[other.length()]), length(other.length()), capacity(other.length())
                {
                    copyMemory(this->data, other.data, this->length);
                }

                /*! Destructor.
                 */
                ~Array()
                {
                    delete [] this->data;
                }

                /*! Assignment operator.
                 */
                Array<T>& operator=(const Array<T>& other)
                {
                    if(this != &other) {

                    }

                    return *this;
                }

                inline int length() const
                {
                    return this->length;
                }
            
        };
    }
}

#endif	/* ARRAY_H */

