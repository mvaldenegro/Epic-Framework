/*
 * File:   OpenCLException.h
 * Author: mvaldenegro
 *
 * Created on 10 de agosto de 2011, 10:05 PM
 */

#ifndef EPIC_OPENCL_OPENCLEXCEPTION_H
#define	EPIC_OPENCL_OPENCLEXCEPTION_H

#include <CL/cl.h>
#include <stdexcept>

#include <epic.core/Core.h>

namespace Epic {
    namespace OpenCL {

        EPIC_INLINE const char *errorCodeToString(cl_int errorCode)
        {
            switch(errorCode) {
                case CL_DEVICE_NOT_FOUND: {
                    return "OpenCL device not found";
                }

                case CL_DEVICE_NOT_AVAILABLE: {
                    return "OpenCL device not available";
                }

                default: {
                    return "Unknown OpenCL error code";
                }
            }
        }

        class OpenCLException : public std::runtime_error
        {
            public:
                OpenCLException(cl_int errorCode)
                : runtime_error(errorCodeToString(errorCode)), mErrorCode(errorCode)
                {
                }

                OpenCLException(const OpenCLException& other)
                : runtime_error(errorCodeToString(other.errorCode())), mErrorCode(other.errorCode())
                {
                }

                virtual ~OpenCLException() throw()
                {
                }

                inline cl_int errorCode() const
                {
                    return mErrorCode;
                }

            private:
                cl_int mErrorCode;
        };
    }
}

#endif	/* EPIC_OPENCL_OPENCLEXCEPTION_H */

