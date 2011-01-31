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
                Pointer() : pointer(nullptr)
                {
                }

                Pointer(T *ptr) : pointer(ptr)
                {
                }

                Pointer(Pointer<T>& orig) : pointer(nullptr)
                {
                    attach(orig);
                }

                ~Pointer()
                {
                    detach();
                }

                Pointer<T>& operator=(T *ptr)
                {
                    attach(ptr);
                }

                Pointer<T>& operator=(Pointer<T>& orig)
                {
                    attach(orig);
                }

                T& operator*()
                {
                    return *(this->pointer);
                }
                const T& operator*() const
                {
                    return *(this->pointer);
                }

                T* operator->()
                {
                    return this->pointer;
                }

                const T* operator->() const
                {
                    return this->pointer;
                }

                operator bool() const;
                bool operator!() const;

                bool isNull() const
                {
                    return this->pointer == nullptr;
                }

                bool isNotNull() const
                {
                    return this->pointer != nullptr;
                }

                void attach(T *ptr)
                {
                    detach();

                    this->pointer = ptr;
                }
                void attach(Pointer<T>& orig)
                {
                    detach();

                    this->pointer = orig.pointer;
                    orig.pointer = nullptr;
                }

                void detach()
                {
                    if(this->pointer != nullptr) {
                        delete pointer;

                        pointer = nullptr;
                    }
                }

            private:
                T *pointer;

        };
    };
};

#endif	/* EPIC_CORE_POINTER_H */

