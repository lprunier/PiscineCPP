#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
    ZombieEvent the_hilltop;
    ZombieEvent the_saviors;
    ZombieEvent alexandria;

    the_hilltop.setZombieType("the Hilltop");
    the_saviors.setZombieType("the Saviors");
    alexandria.setZombieType("Alexandria");
    
    Zombie  *horde[4];

    std::cout << "_______ THE HEAP _______" << std::endl << std::endl;

    horde[0] = the_hilltop.newZombie("Jim");
    horde[1] = alexandria.newZombie("Theresa");
    horde[2] = the_hilltop.newZombie("John");
    horde[2]->announce();
    horde[3] = the_saviors.newZombie("Marry");
    horde[1]->announce();
    
    for (int i = 0; i < 4; i++) {
        delete horde[i];
    }

    std::cout << "________________________" << std::endl << std::endl;
    std::cout << "_________ STACK ________" << std::endl << std::endl;

    the_saviors.randomChump();        
    alexandria.randomChump();        
    the_saviors.randomChump();        
    the_saviors.randomChump();        
    the_hilltop.randomChump();        
    the_hilltop.randomChump();        
    the_saviors.randomChump();        
    alexandria.randomChump();        
    alexandria.randomChump();        
    the_hilltop.randomChump();        
    alexandria.randomChump();        

    std::cout << "________________________" << std::endl;
    

    return 0;
}