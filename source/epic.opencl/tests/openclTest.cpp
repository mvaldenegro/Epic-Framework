/*
 * File:   openclTest.cpp
 * Author: mvaldenegro
 *
 * Created on 11 de agosto de 2011, 12:16 AM
 */

#include <iostream>
#include <epic.opencl/Platform.h>
#include <epic.opencl/Device.h>
#include <epic.opencl/Context.h>
#include <epic.opencl/Program.h>
#include <epic.opencl/Kernel.h>
#include <epic.opencl/Buffer.h>
#include <epic.opencl/CommandQueue.h>

using namespace std;

using Epic::Core::Array;

using Epic::OpenCL::Platform;
using Epic::OpenCL::Device;
using Epic::OpenCL::Context;
using Epic::OpenCL::Program;
using Epic::OpenCL::Kernel;
using Epic::OpenCL::Buffer;
using Epic::OpenCL::CommandQueue;
using Epic::OpenCL::NDRange;

const char *kernel = "kernel void sum(global int* a, global int *b, global int *out)\n"
"{\n"
"    int i = get_global_id(0);\n"
"    out[i] = a[i] + b[i];\n"
"}";

const int inputA[5] = { 1, 2, 3, 4, 5 };
const int inputB[5] = { 5, 4, 3, 2, 1 };

int main(int argc, char** argv)
{
    Platform platform = Platform::getPlatformIDs().at(0);
    Device device = platform.devices(CL_DEVICE_TYPE_ALL).at(0);
    Context context(platform, Array<Device>() << device);

    cout << "profile: " << platform.profile() << endl;
    cout << "version: " << platform.version() << endl;
    cout << "name: " << platform.name() << endl;
    cout << "vendor: " << platform.vendor() << endl;
    cout << "extensions: " << platform.extensions() << endl;

    Program program = context.createProgram(kernel);
    program.build();
    
    Kernel sum = program.createKernel("sum");
    
    cout << "kernel name: " << sum.functionName() << endl;
    cout << "kernel num args: " << sum.numberOfArguments() << endl;
    
    Buffer bufA = context.createBuffer(CL_MEM_READ_ONLY, 5 * sizeof(float));
    Buffer bufB = context.createBuffer(CL_MEM_READ_ONLY, 5 * sizeof(float));
    Buffer out  = context.createBuffer(CL_MEM_WRITE_ONLY, 5 * sizeof(float));

    sum.setArgument(0, bufA);
    sum.setArgument(1, bufB);
    sum.setArgument(2, out);

    CommandQueue queue = context.createCommandQueue(device, 0);
    queue.enqueueWriteBuffer(bufA, true, 0, 5 * sizeof(float), (void *) inputA);
    queue.enqueueWriteBuffer(bufB, true, 0, 5 * sizeof(float), (void *) inputB);

    queue.enqueueNDRangeKernel(sum, NDRange(), NDRange(5), NDRange(1));

    int *p = new int[5];
    queue.enqueueReadBuffer(out, true, 0, 5 * sizeof(float), p);

    for(int i = 0; i < 5; i++) {
        cout << p[i] << endl;
    }
  
    return 0;
}

