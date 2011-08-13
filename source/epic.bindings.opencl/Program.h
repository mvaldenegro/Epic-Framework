/*
 * File:   Program.h
 * Author: mvaldenegro
 *
 * Created on 12 de agosto de 2011, 12:55 PM
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#include <epic.core/Core.h>
#include <epic.core/ASCIIString.h>
#include <epic.core/Array.h>

#include <CL/opencl.h>

#include <epic.bindings.opencl/Device.h>

namespace Epic {
    namespace OpenCL {

        class Program {
            public:
                Program();
                Program(cl_program program);
                Program(const Program& other);
                ~Program();

                EPIC_INLINE cl_program programHandle() const
                {
                    return mProgram;
                }

                EPIC_INLINE cl_uint numberOfDevices() const
                {
                    cl_uint ret = 0;

                    getInfo(CL_PROGRAM_NUM_DEVICES, sizeof(cl_uint), &ret);

                    return ret;
                }

                Epic::Core::Array<Device> devices() const;

                size_t getInfoSize(cl_program_info paramName) const;
                void getInfo(cl_program_info paramName, size_t paramValueSize, void *paramValue) const;

                size_t getBuildInfoSize(cl_program_build_info paramName, const Device& device) const;
                void getBuildInfo(cl_program_build_info paramName, const Device& device, size_t paramValueSize, void *paramValue) const;

                bool build(const Epic::Core::Array<Device>& devices = Epic::Core::Array<Device>(),
                           const Epic::Core::ASCIIString& options = Epic::Core::ASCIIString()) const;

            private:
                cl_program mProgram;
        };
    }
}

#endif	/* PROGRAM_H */

