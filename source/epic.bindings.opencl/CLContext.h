/* 
 * File:   CLContext.h
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:44 PM
 */

#ifndef EPIC_OPENCL_CLCONTEXT_H
#define	EPIC_OPENCL_CLCONTEXT_H

#include <CL/cl.h>

namespace Epic {
    namespace OpenCL {
        class Context {
            public:
            private:
                cl_context mContext;
        };
    }
};

class CLContext {
public:
    CLContext();
    CLContext(const CLContext& orig);
    virtual ~CLContext();
private:

};

#endif	/* EPIC_OPENCL_CLCONTEXT_H */

