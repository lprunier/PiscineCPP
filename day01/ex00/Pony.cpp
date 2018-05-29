#include "Pony.hpp"

Pony::Pony(std::string name, std::string placement, std::string runner, int rank) {
    this->_name = name;
    this->_placement = placement;
    this->_runner = runner;
    this->_rank = rank;
    std::cout << "Start of the race of the \033[32m" << placement << "\033[0m for \033[33m" << name << "\033[0m with his runner \033[35m" << runner << "\033[0m!" << std::endl;
}

Pony::~Pony(void) {
    std::cout << "End of the race!" << std::endl;
    std::cout << "\033[33m" << this->_name << "\033[0m is at the rank \033[32m" << this->_rank << "\033[0m" << std::endl;
    if (this->_rank <= 4)
        std::cout << "Congrats!!" << std::endl;
}

std::string Pony::get_name(void) const {
    return (this->_name);
}

std::string Pony::get_placement(void) const {
    return (this->_placement);
}

std::string Pony::get_runner(void) const {
    return (this->_runner);
}

int         Pony::get_rank(void) const {
    return (this->_rank);
}