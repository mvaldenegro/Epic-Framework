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

#include "epic.bindings.opencl/OpenCLException.h"

using namespace std;

using Epic::Core::Array;

using Epic::OpenCL::Platform;
using Epic::OpenCL::Device;
using Epic::OpenCL::Context;

/*
 *
 */
int main(int argc, char** argv)
{
    Platform platform = Platform::getPlatformIDs().at(0);

    Array<Device> devices = platform.devices(CL_DEVICE_TYPE_ALL);

    cout << "How many devices? " << devices.count() << endl;

    for(size_t i = 0; i < devices.count(); i++) {
        cout << "Device " << i << " = " << devices[i].name() << endl;
        cout << "Device ID " << devices[i].deviceID() << endl;
    }

    Context context(platform, devices);

    cout << "profile: " << platform.profile() << endl;
    cout << "version: " << platform.version() << endl;
    cout << "name: " << platform.name() << endl;
    cout << "vendor: " << platform.vendor() << endl;
    cout << "extensions: " << platform.extensions() << endl;

    Array<Device> devises = context.devices();

    for(size_t i = 0; i < devises.count(); i++) {
        cout << "Device " << i << " = " << devises[i].name() << endl;
        cout << "Device ID " << devises[i].deviceID() << endl;
    }

    return 0;
}

