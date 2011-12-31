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
