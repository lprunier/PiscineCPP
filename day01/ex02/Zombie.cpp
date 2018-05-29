#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name): type(type), name(name) {
    std::cout << "Zombie " << name << " from " << type << " is created." << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie" << this->name << " from " << this->type << "is delated." << std::endl;
}

void    Zombie::announce(void) const {
    std::cout << "Zombie" << this->name << " from " << this->type << "said: Braiiiiiiinnnssss..." << std::endl;
}