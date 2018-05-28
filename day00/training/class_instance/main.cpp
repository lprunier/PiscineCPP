#include <iostream>
#include "sample.class.hpp"

int main(void) {

    sample  instance;
    sample  *instancep = &instance;

    int     sample::*p = NULL;
    void    (sample::*f)(void) const;

    p = &sample::foo;

    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance.*p = 21;
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instancep->*p = 42;
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    
    f = &sample::bar;

    (instance.*f)();
    (instancep->*f)();
    
    return 0;
}