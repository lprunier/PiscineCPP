#include <iostream>
#include "sample.class.hpp"

sample::sample(float const f) : pi(f), qd(42) {
    std::cout << "Constructor called." << std::endl;
    return ;
}

sample::~sample(void) {
    std::cout << "Destructor called." << std::endl;
    return ;
}

void    sample::bar(void) const {
    std::cout << "this->pi: " << this->pi << std::endl;
    std::cout << "this->qd: " << this->qd << std::endl;

    // this->pi = 3.1415;
    return ;
}