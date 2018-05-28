#include <iostream>
#include "sample.class.hpp"

sample::sample(void) {

    std::cout << "Constructor called." << std::endl;
    
    this->publicFoo = 0;
    std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
    this->_privateFoo = 0;
    std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

    this->publicBar();
    this->_privateBar();
    
    return ;
}

sample::~sample(void) {
    std::cout << "Destructor called." << std::endl;
    return ;
}

void    sample::publicBar(void) const {
    std::cout << "Member function publicBar called." << std::endl;
    return ;
}

void    sample::_privateBar(void) const {
    std::cout << "Member function _privateBar called." << std::endl;
    return ;
}