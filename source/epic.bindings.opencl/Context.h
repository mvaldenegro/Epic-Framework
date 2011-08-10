/*
 * File:   CLContext.h
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:44 PM
 */

#ifndef EPIC_OPENCL_CLCONTEXT_H
#define	EPIC_OPENCL_CLCONTEXT_H

#include <epic.core/Array.h>
#include <CL/cl.h>

namespace Epic {
    namespace OpenCL {
        class Context {
            public:
                Context(const Epic::Core::Array<Device>& devices);
                Context(const Context& other);
                ~Context();

            private:
                cl_context mContext;
        };
    }
};

#endif	/* EPIC_OPENCL_CLCONTEXT_H */

