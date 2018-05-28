#include <iostream>
#include "sample.class.hpp"

sample::sample(void) {
    std::cout << "Constructor called." << std::endl;

    this->foo = 42;
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();
    return ;
}

sample::~sample(void) {
    std::cout << "Destructor called." << std::endl;
    return ;
}

void    sample::bar(void) {
    std::cout << "Member function called." << std::endl;
    return ;
}