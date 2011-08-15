/* 
 * File:   Sampler.cpp
 * Author: mvaldenegro
 * 
 * Created on 14 de agosto de 2011, 10:14 PM
 */

#include "Sampler.h"
#include "OpenCLException.h"

namespace Epic {
namespace OpenCL {

    Sampler::Sampler()
    : mSampler(0)
    {
    }
    
    Sampler::Sampler(cl_sampler sampler)
    : mSampler(sampler)
    {
    }

    Sampler::Sampler(const Sampler& other)
    : mSampler(other.mSampler)
    {
    }

    Sampler::~Sampler()
    {
    }

    size_t Sampler::getInfoSize(cl_context_info paramName) const
    {
        size_t ret;
        cl_int err = 0;

        err = clGetSamplerInfo(samplerHandle(), paramName, 0, nullptr, &ret);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }

        return ret;
    }

    void Sampler::getInfo(cl_context_info paramName, size_t paramValueSize, void *paramValue) const
    {
        cl_int err = 0;
        size_t written = 0;

        err = clGetSamplerInfo(samplerHandle(), paramName, paramValueSize, paramValue, &written);

        if(err != CL_SUCCESS) {
            throw OpenCLException(err);
        }
    }
    
}
}