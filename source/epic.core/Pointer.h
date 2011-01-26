/* 
 * File:   Pointer.h
 * Author: hunts
 *
 * Created on 23 de agosto de 2010, 10:36 PM
 */

#ifndef EPIC_CORE_POINTER_H
#define	EPIC_CORE_POINTER_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {

        /*! Ownership-based smart pointer.
         *
         */

        template<typename T>
        class Pointer {
            public:
                Pointer();
                Pointer(T *pointer);
                Pointer(const Pointer<T>& orig);
                ~Pointer();

                T& operator*() const;
                T *operator->() const;

                operator bool() const;
                bool operator!() const;

            private:
                T *mPointer;

        };

        template<typename T>
        Pointer<T>::Pointer() : mPointer(nullptr)
        {
        }

        template<typename T>
        Pointer<T>::Pointer(T *pointer) : mPointer(pointer)
        {
        }

    };
};

#endif	/* EPIC_CORE_POINTER_H */

