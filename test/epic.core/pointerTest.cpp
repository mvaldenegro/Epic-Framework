/* 
 * File:   PointerTest.cpp
 * Author: hunts
 *
 * Created on 31 de enero de 2011, 09:02 PM
 */

#include <epic.core/Pointer.h>

#include <iostream>

class PtrTest
{
    public:
        void foo()
        {
            std::cout << "Foo" << std::endl;
        }

        void bar()
        {
            std::cout << "Bar" << std::endl;
        }
};

int main(int argc, char** argv)
{
    Epic::Core::Pointer<PtrTest> p(new PtrTest());
    
    p->foo();
    p->bar();

    p = nullptr;

    p->bar();

    return 0;
}

