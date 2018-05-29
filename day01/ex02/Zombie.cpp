#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name): type(type), name(name) {
    std::cout << "Zombie \033[32m" << name << "\033[0m from " << type << " is created." << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie \033[31m" << this->name << "\033[0m from " << this->type << " is deleted." << std::endl;
}

void    Zombie::announce(void) const {
    std::cout << "Zombie " << this->name << " from " << this->type << " said: Braiiiiiiinnnssss..." << std::endl;
}