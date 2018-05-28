#include <iostream>
#include "sample.class.hpp"

sample::sample(void) {

    std::cout << "Constructor called." << std::endl;
    
    this->setFoo(0);
    std::cout << "this->getFoo: " << this->getFoo() << std::endl;

    return ;
}

sample::~sample(void) {
    std::cout << "Destructor called." << std::endl;
    return ;
}

int     sample::getFoo(void) const {
    
    return this->_foo;
}

void    sample::setFoo(int v) {
    
    if (v >= 0)
        this->_foo = v;

    return;
}