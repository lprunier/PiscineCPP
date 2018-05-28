#include <iostream>
#include "sample.class.hpp"

int main(void) {

    sample  instance;

    instance.setFoo(42);
    std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
    instance.setFoo(-42);
    std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
    
    return 0;
}