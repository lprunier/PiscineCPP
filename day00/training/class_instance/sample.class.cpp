#include <iostream>
#include "sample.class.hpp"

sample::sample(void) {

    std::cout << "Constructor called." << std::endl;
    return ;
}

sample::~sample(void) {

    std::cout << "Destructor called." << std::endl;
    return ;
}

void    sample::bar(void) const {
    std::cout << "Member function bar called." << std::endl;
    return ;
}