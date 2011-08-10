/*
 * File:   Platform.h
 * Author: mvaldenegro
 *
 * Created on 8 de agosto de 2011, 01:44 AM
 */

#ifndef EPIC_OPENCL_PLATFORM_H
#define	EPIC_OPENCL_PLATFORM_H

#include <CL/cl.h>
#include <epic.core/Array.h>

namespace Epic {
    namespace OpenCL {

        class Platform
        {
            public:
                Platform(const Platform& platform);
                ~Platform();

                EPIC_INLINE cl_platform_id platformID() const
                {
                    return mPlatformID;
                }

                static Epic::Core::Array<Platform> getPlatformIDs();

            private:
                Platform(cl_platform_id platformID);
                cl_platform_id mPlatformID;
        };
    }
}

#endif	/* EPIC_OPENCL_PLATFORM_H */

