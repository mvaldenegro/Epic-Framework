/* 
 * File:   imageTest.cpp
 * Author: mvaldenegro
 *
 * Created on 14 de agosto de 2011, 09:33 PM
 */

#include <iostream>

using namespace std;

#include <epic.image/Image.h>
#include <epic.image/RGBA8Image.h>

using Epic::Image::Image;
using Epic::Image::RGBA8Image;
using Epic::Image::PixelFormat;

int main(int argc, char** argv)
{
    Image *image = Image::createFromFormat(10, 10, PixelFormat::RGBA8);
    
    cout << "Pixel data size: " << image->pixelDataSize() << endl;

    return 0;
}

