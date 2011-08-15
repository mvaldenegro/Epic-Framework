/* 
 * File:   Sampler.h
 * Author: mvaldenegro
 *
 * Created on 14 de agosto de 2011, 10:14 PM
 */

#ifndef EPIC_OPENCL_SAMPLER_H
#define	EPIC_OPENCL_SAMPLER_H

#include <epic.core/Core.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Sampler
        {
            public:
                Sampler();
                Sampler(cl_sampler sampler);
                Sampler(const Sampler& other);
                ~Sampler();
                
                EPIC_INLINE cl_sampler samplerHandle() const
                {
                    return mSampler;
                }
                
                EPIC_INLINE cl_addressing_mode addressingMode() const
                {
                    cl_addressing_mode ret = 0;
                    
                    getInfo(CL_SAMPLER_ADDRESSING_MODE, sizeof(cl_addressing_mode), &ret);
                    
                    return ret;
                }
                
                EPIC_INLINE cl_filter_mode filterMode() const
                {
                    cl_filter_mode ret = 0;
                    
                    getInfo(CL_SAMPLER_FILTER_MODE, sizeof(cl_filter_mode), &ret);
                    
                    return ret;
                }
                
                EPIC_INLINE bool normalizedCoords() const
                {
                    cl_bool ret = 0;
                    
                    getInfo(CL_SAMPLER_NORMALIZED_COORDS, sizeof(cl_bool), &ret);
                    
                    return (ret == CL_TRUE);
                }
                
                size_t getInfoSize(cl_sampler_info paramName) const;
                void getInfo(cl_sampler_info paramName, size_t paramValueSize, void *paramValue) const;
                
            private:
                cl_sampler mSampler;
        };

    }
}

#endif	/* EPIC_OPENCL_SAMPLER_H */

