#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class   Zombie {
public:
    
    Zombie(std::string type, std::string name);
    ~Zombie(void);
    
    std::string type;
    std::string name;

    void    announce(void) const;
};

#endif