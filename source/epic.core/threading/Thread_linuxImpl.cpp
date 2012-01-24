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

#include "Thread.h"

#include <pthread.h>

static void *threadFunction(void *threadClass)
{
    Epic::Core::Threading::Thread *thread = static_cast<Epic::Core::Threading::Thread *>(threadClass);

    thread->run();

    return nullptr;
}

namespace Epic {
    namespace Core {
        namespace Threading {

            class Thread::PrivateData
            {
                public:
                    pthread_t threadId;
            };

            Thread::Thread()
            : d(new PrivateData())
            {
            }

            Thread::Thread(unsigned long tid)
            : d(new PrivateData())
            {
                d->threadId = tid;
            }

            Thread::~Thread()
            {
                pthread_detach(d->threadId);
            }

            unsigned long Thread::threadId() const
            {
                return d->threadId;
            }

            void Thread::start()
            {
                pthread_create(&(d->threadId), nullptr, threadFunction, static_cast<void *>(this));
            }

            class Thread::ExistingThread : public Thread
            {
                public:
                    ExistingThread(unsigned long tid) : Thread(tid)
                    {
                    }

                    virtual ~ExistingThread()
                    {
                    }

                    void run()
                    {
                    }
            };

            Thread *Thread::currentThread()
            {
                return new ExistingThread(pthread_self());
            }

        } /* namespace Threading */
    } /* namespace Core */
} /* namespace Epic */
