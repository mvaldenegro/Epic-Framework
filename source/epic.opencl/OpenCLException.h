/*
 * File:   OpenCLException.h
 * Author: mvaldenegro
 *
 * Created on 10 de agosto de 2011, 10:05 PM
 */

#ifndef EPIC_OPENCL_OPENCLEXCEPTION_H
#define	EPIC_OPENCL_OPENCLEXCEPTION_H

#include <CL/opencl.h>
#include <stdexcept>

#include <epic.core/Core.h>

namespace Epic {
    namespace OpenCL {

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
                
                static EPIC_INLINE const char *errorCodeToString(cl_int errorCode)
                {
                    switch(errorCode) {
                        case CL_DEVICE_NOT_FOUND: {
                            return "OpenCL device not found";
                        }

                        case CL_DEVICE_NOT_AVAILABLE: {
                            return "OpenCL device not available";
                        }

                        case CL_COMPILER_NOT_AVAILABLE: {
                            return "OpenCL compiler is not available";
                        }

                        case CL_MEM_OBJECT_ALLOCATION_FAILURE: {
                            return "Memory object allocation failure";
                        }

                        case CL_OUT_OF_RESOURCES: {
                            return "Out of resources";
                        }

                        case CL_OUT_OF_HOST_MEMORY: {
                            return "Out of host memory";
                        }

                        case CL_PROFILING_INFO_NOT_AVAILABLE: {
                            return "Profiling information not available";
                        }

                        case CL_MEM_COPY_OVERLAP: {
                            return "Memory object copy overlaps";
                        }

                        case CL_IMAGE_FORMAT_MISMATCH: {
                            return "Image format mismatch";
                        }

                        case CL_IMAGE_FORMAT_NOT_SUPPORTED: {
                            return "Image format not supported";
                        }

                        case CL_BUILD_PROGRAM_FAILURE: {
                            return "Build program failure";
                        }

                        case CL_MAP_FAILURE: {
                            return "Map failure";
                        }

                        case CL_MISALIGNED_SUB_BUFFER_OFFSET: {
                            return "Misaligned subbuffer offset";
                        }

                        case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST: {
                            return "Execution statis error for events in wait list";
                        }

                        case CL_INVALID_VALUE: {
                            return "Invalid value";
                        }

                        case CL_INVALID_DEVICE_TYPE: {
                            return "Invalid device type";
                        }

                        case CL_INVALID_PLATFORM: {
                            return "Invalid platform";
                        }

                        case CL_INVALID_DEVICE: {
                            return "Invalid device";
                        }

                        case CL_INVALID_CONTEXT: {
                            return "Invalid context";
                        }

                        case CL_INVALID_QUEUE_PROPERTIES: {
                            return "Invalid queue properties";
                        }

                        case CL_INVALID_COMMAND_QUEUE: {
                            return "Invalid command queue";
                        }

                        case CL_INVALID_HOST_PTR: {
                            return "Invalid host pointer";
                        }

                        case CL_INVALID_MEM_OBJECT: {
                            return "Invalid memory object";
                        }

                        case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR: {
                            return "Invalid image format descriptor";
                        }

                        case CL_INVALID_IMAGE_SIZE: {
                            return "Invalid image size";
                        }

                        case CL_INVALID_SAMPLER: {
                            return "Invalid sampler";
                        }

                        case CL_INVALID_BINARY: {
                            return "Invalid binary";
                        }

                        case CL_INVALID_BUILD_OPTIONS: {
                            return "Invalid build options";
                        }

                        case CL_INVALID_PROGRAM: {
                            return "Invalid program";
                        }

                        case CL_INVALID_PROGRAM_EXECUTABLE: {
                            return "Invalid program executable";
                        }

                        case CL_INVALID_KERNEL_NAME: {
                            return "Invalid kernel name";
                        }

                        case CL_INVALID_KERNEL_DEFINITION: {
                            return "Invalid kernel definition";
                        }

                        case CL_INVALID_KERNEL: {
                            return "Invalid kernel";
                        }

                        case CL_INVALID_ARG_INDEX: {
                            return "Invalid argument index";
                        }

                        case CL_INVALID_ARG_VALUE: {
                            return "Invalid argument value";
                        }

                        case CL_INVALID_ARG_SIZE: {
                            return "Invalid argument size";
                        }

                        case CL_INVALID_KERNEL_ARGS: {
                            return "Invalid kernel arguments";
                        }

                        case CL_INVALID_WORK_DIMENSION: {
                            return "Invalid work dimension";
                        }

                        case CL_INVALID_WORK_GROUP_SIZE: {
                            return "Invalid workgroup size";
                        }

                        case CL_INVALID_WORK_ITEM_SIZE: {
                            return "Invalid work item size";
                        }

                        case CL_INVALID_GLOBAL_OFFSET: {
                            return "Invalid global offset";
                        }

                        case CL_INVALID_EVENT_WAIT_LIST: {
                            return "Invalid event wait list";
                        }

                        case CL_INVALID_EVENT: {
                            return "Invalid event";
                        }

                        case CL_INVALID_OPERATION: {
                            return "Invalid operation";
                        }

                        case CL_INVALID_GL_OBJECT: {
                            return "Invalid OpenGL object";
                        }

                        case CL_INVALID_BUFFER_SIZE: {
                            return "Invalid buffer size";
                        }

                        case CL_INVALID_MIP_LEVEL: {
                            return "Invalid mipmap level";
                        }

                        case CL_INVALID_GLOBAL_WORK_SIZE: {
                            return "Invalid global work size";
                        }

                        case CL_INVALID_PROPERTY: {
                            return "Invalid property";
                        }

                        default: {
                            return "Unknown OpenCL error code";
                        }
                    }
                }

            private:
                cl_int mErrorCode;
        };

        #define EPIC_OPENCL_CHECK_ERROR(err)    if((err) != CL_SUCCESS) {  throw OpenCLException((err)); }
    }
}

#endif	/* EPIC_OPENCL_OPENCLEXCEPTION_H */

