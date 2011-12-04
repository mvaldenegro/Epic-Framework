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

                /*! Constructor.
                 *
                 * Constructs a null pointer.
                 */

                Pointer() : pointer(nullptr)
                {
                }

                /*! Constructor.
                 *
                 * Constructs a pointer, taking ownership of @a ptr.
                 */

                Pointer(T *ptr) : pointer(ptr)
                {
                }

                /*! Constructs a pointer, taking ownership of the pointer contained by @a orig.
                 * @a orig will point to null.
                 */

                Pointer(Pointer<T>& orig) : pointer(nullptr)
                {
                    attach(orig);
                }

                /*! Destructor.
                 *
                 * Destroys this instance, freeing the contained pointer with operator delete.
                 */

                ~Pointer()
                {
                    detach();
                }

                /*! Assignment operator.
                 *
                 * Takes ownership of @a ptr, freeing the current pointer.
                 */

                Pointer<T>& operator=(T *ptr)
                {
                    attach(ptr);

                    return *this;
                }

                /*! Assignment operator.
                 *
                 * Takes ownership of the pointer contained by @a orig.
                 * @a orig will point to null.
                 */

                Pointer<T>& operator=(Pointer<T>& orig)
                {
                    attach(orig);

                    return *this;
                }

                /*! Dereference operator.
                 * 
                 * Dereferences the contained pointer and returns a reference to the pointed object.
                 */

                inline T& operator*()
                {
                    return *(this->pointer);
                }

                /*! Dereference operator.
                 *
                 * Dereferences the contained pointer and returns a constant reference to the pointed object.
                 */

                inline const T& operator*() const
                {
                    return *(this->pointer);
                }

                /*! Arrow operator.
                 *
                 * This operator implements pointer semantics, allows the usage of Pointer as any raw pointer.
                 */

                inline T* operator->()
                {
                    return this->pointer;
                }

                /*! Arrow operator.
                 *
                 * This operator implements pointer semantics, allows the usage of Pointer as any raw pointer.
                 */

                inline const T* operator->() const
                {
                    return this->pointer;
                }

                /*! Conversion to bool operator.
                 *
                 * Implement the indirect conversion idioms.
                 */

                operator bool() const
                {
                    return this->pointer != nullptr;
                }

                /*! Negation operator.
                 *
                 * Returns true if the contained pointer is null, and false otherwise.
                 */

                bool operator!() const
                {
                    return isNull();
                }

                /*! Pointer conversion operator.
                 * 
                 * This conversion operator allows passing a Pointer<T> to a function that takes a pointer to T.
                 */

                operator T*() const
                {
                    return this->pointer;
                }

                /*! This function returns ownership of the contained pointer to the caller. Returns the contained pointer
                 * and sets this instance to null.
                 */

                T* take()
                {
                    T* ret = this->pointer;
                    this->pointer = nullptr;

                    return ret;
                }

                /*! Returns true if the contained pointer is null, and false otherwise.
                 */

                bool isNull() const
                {
                    return this->pointer == nullptr;
                }

                /*! Returns true if the contained pointer is non-null, and false otherwise.
                 */

                bool isNotNull() const
                {
                    return this->pointer != nullptr;
                }

                /*! Attach operation.
                 *
                 * The attach operation takes ownership of @a ptr, freeing the contained pointer first.
                 */

                void attach(T *ptr)
                {
                    detach();

                    this->pointer = ptr;
                }

                /*! Attach operation.
                 *
                 * The attach operation takes ownership of the pointer contained in @a orig,
                 * first detaching from the current pointer in this instance. @a orig will point to null
                 * after this operation completes.
                 */

                void attach(Pointer<T>& orig)
                {
                    detach();

                    this->pointer = orig.pointer;
                    orig.pointer = nullptr;
                }

                /*! Detach operation.
                 *
                 * The detach operation
                 */

                void detach()
                {
                    if(this->pointer != nullptr) {
                        delete this->pointer;

                        this->pointer = nullptr;
                    }
                }

            private:
                T *pointer;

        };
    }
}

#endif	/* EPIC_CORE_POINTER_H */

