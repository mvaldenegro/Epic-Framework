/*
 * File:   SharedData.h
 * Author: hunts
 *
 * Created on 30 de enero de 2011, 02:33 AM
 */

#ifndef EPIC_CORE_SHAREDDATA_H
#define	EPIC_CORE_SHAREDDATA_H

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {

        /*! Sharable pointer.
         *
         * This class represents a raw pointer which can be referenced by multiple instances of this class.
         */
        template<typename T>
        class SharedPointer
        {
            private:

                class InternalSharedData
                {
                    public:
                        T *pointer;
                        int referenceCount;

                        InternalSharedData(T *ptr) : pointer(ptr), referenceCount(1)
                        {
                        }

                        ~InternalSharedData()
                        {
                            delete pointer;
                        }
                };

                InternalSharedData *sharedData;

            public:

                /*! Constructor.
                 *
                 * Constructs a shared pointer, initializing it with a raw pointer.
                 * This smart pointer takes ownership of the raw pointer.
                 */

                SharedPointer(T *ptr = nullptr) : sharedData(new InternalSharedData(ptr))
                {
                }

                /*! Constructor.
                 *
                 * Constructs a shared pointer, initializing it with the raw pointer of another shared pointer instance.
                 * Thus the raw pointer is shared among both smart pointers.
                 */

                SharedPointer(const SharedPointer<T>& other) : sharedData(nullptr)
                {
                    attach(other);
                }

                /*! Destructor.
                 *
                 * Destroys this shared pointer. If the reference count of the shared pointer is zero,
                 * the raw pointer is deleted using operator delete.
                 */

                ~SharedPointer()
                {
                    detach();
                }

                /*! Assignment operator.
                 *
                 * Makes this shared pointer point to the raw pointer ptr, attaching to it.
                 * This smart pointer takes ownership of ptr.
                 */

                SharedPointer<T>& operator=(T *ptr)
                {
                    attach(ptr);

                    return *this;
                }

                /*! Assignment operator.
                 *
                 * Makes this shared pointer point to other's raw pointer, attaching to it.
                 * The raw pointer of @a other is shared with this instance.
                 */

                SharedPointer<T>& operator=(const SharedPointer<T>& other)
                {
                    attach(other);

                    return *this;
                }

                /*! Dereference operator.
                 *
                 * Dereferences this pointer and returns a reference to the pointed object.
                 */

                inline T& operator*()
                {
                    return *(this->sharedData.pointer);
                }

                /*! Dereference operator.
                 *
                 * Dereferences this pointer and returns a constant reference to the pointer object.
                 */

                inline const T& operator*() const
                {
                    return *(this->sharedData->pointer);
                }

                /*! Arrow operator.
                 *
                 * This operator implements pointer semantics, allows the usage of SharedPointer as any raw pointer.
                 */

                inline T* operator->()
                {
                    return this->sharedData->pointer;
                }

                inline const T* operator->() const
                {
                    return this->sharedData->pointer;
                }

                /*! Returns true if this pointer is null, false otherwise.
                 */

                inline bool isNull() const
                {
                    return !isNotNull();
                }

                /*! Returns true if this pointer is not null, false otherwise.
                 */

                inline bool isNotNull() const
                {
                    return (this->sharedData != nullptr) && (this->sharedData->pointer != nullptr);
                }
                
                /*! Returns true if this pointer is shared (referenceCount() > 1), or false otherwise.
                 */
                
                inline bool isShared() const
                {
                    return referenceCount() > 1;
                }

                /*! Attach operation.
                 */

                void attach(T *ptr)
                {
                    if(isNotNull()) {

                        if(ptr != this->sharedData.pointer) {
                            detach();

                            this->sharedData = new InternalSharedData(ptr);
                        }

                    } else {

                        this->sharedData = new InternalSharedData(ptr);
                    }
                }

                /*! Attach operation.
                 */

                void attach(const SharedPointer<T>& other)
                {
                    if(this != &other) {

                        detach();

                        this->sharedData = other.sharedData;
                        this->sharedData->referenceCount++;
                    }
                }

                /*! Detach operation.
                 *
                 *
                 */

                void detach()
                {
                    if(this->sharedData != nullptr) {

                        this->sharedData->referenceCount--;

                        if(this->sharedData->referenceCount == 0) {
                            delete this->sharedData;

                            this->sharedData = nullptr;
                        }
                    }
                }

                int referenceCount()
                {
                    return this->sharedData->referenceCount;
                }
        };
    }
}

#endif	/* SHAREDDATA_H */

