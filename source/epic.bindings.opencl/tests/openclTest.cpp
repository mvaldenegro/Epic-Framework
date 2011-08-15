/*
 * File:   openclTest.cpp
 * Author: mvaldenegro
 *
 * Created on 11 de agosto de 2011, 12:16 AM
 */

#include <iostream>
#include <epic.bindings.opencl/Platform.h>
#include <epic.bindings.opencl/Device.h>
#include <epic.bindings.opencl/Context.h>
#include <epic.bindings.opencl/Program.h>
#include <epic.bindings.opencl/Kernel.h>
#include <epic.bindings.opencl/Buffer.h>

using namespace std;

using Epic::Core::Array;

using Epic::OpenCL::Platform;
using Epic::OpenCL::Device;
using Epic::OpenCL::Context;
using Epic::OpenCL::Program;
using Epic::OpenCL::Kernel;
using Epic::OpenCL::Buffer;

const char *kernel = "kernel void sum(global int* a, global int *b, global int *out)\n"
"{\n"
"    for(int i = 0; i < 5; i++) {\n"
"        out[i] = a[i] + b[i];\n"
"    }\n"
"}";

int main(int argc, char** argv)
{
    Platform platform = Platform::getPlatformIDs().at(0);
    Array<Device> devices = platform.devices(CL_DEVICE_TYPE_ALL);
    Context context(platform, devices);

    cout << "profile: " << platform.profile() << endl;
    cout << "version: " << platform.version() << endl;
    cout << "name: " << platform.name() << endl;
    cout << "vendor: " << platform.vendor() << endl;
    cout << "extensions: " << platform.extensions() << endl;

    Program program = context.createProgram(kernel);
    program.build();
    
    Kernel kernel = program.createKernel("sum");
    
    cout << "kernel name: " << kernel.functionName() << endl;
    cout << "kernel num args: " << kernel.numberOfArguments() << endl;
    
    Buffer buf = context.createBuffer(CL_MEM_READ_ONLY, 10);
  
    return 0;
}

