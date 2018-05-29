/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:07:39 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 17:07:40 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <random>

void    ZombieEvent::setZombieType(std::string type) {
    this->_type = type;
}

Zombie  *ZombieEvent::newZombie(std::string name) {
    Zombie  *zb = new Zombie(this->_type, name);
    return zb;
}

void    ZombieEvent::randomChump(void) {
    std::string names [15] = {"Negan", "Carl", "Rick", "Daryl", "Gleen", "Michonne", "Maggie", "Carol", "Rosita", "Dwight", "Morgan", "Eugene", "Jadis", "Simon", "Ezekiel"};

    std::string name = names[(std::rand() * std::time(NULL) % 15 + std::rand()) % 15];
    Zombie  zb(this->_type, name);
    zb.announce();  
}
