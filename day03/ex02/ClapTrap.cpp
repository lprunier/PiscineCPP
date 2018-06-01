/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:10 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:11 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    this->_hit = 100;
    this->_max_hit = 100;
    this->_level = 1;
    this->_name = "no name";
    std::cout << "Clap : A new " << this->_name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
    this->_hit = 100;
    this->_max_hit = 100;
    this->_level = 1;
    std::cout << "Clap : A new " << this->_name << " is born!" << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << "Clap : ";
    *this = copy;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Clap" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &copy) {
	this->_hit = copy.get_hit();
    this->_max_hit = copy.get_max_hit();
    this->_energy = copy.get_energy();
    this->_max_energy = copy.get_max_energy();
    this->_level = copy.get_level();
    this->_name = copy.get_name();
    this->_melee_attack_damage = copy.get_melee_attack_damage();
    this->_ranged_attack_damage = copy.get_ranged_attack_damage();
    this->_armor_damage_reduction = copy.get_armor_damage_reduction();
	return *this;
}


unsigned int    ClapTrap::rangedAttack(std::string const & target) {
    std::cout << this->_name << " attaks " << target << " at range causing " << this->_ranged_attack_damage << " points of damages." << std::endl;
    return this->_ranged_attack_damage;
}

unsigned int    ClapTrap::meleeAttack(std::string const & target) {
    std::cout << this->_name << " attaks " << target << " at melee causing " << this->_melee_attack_damage << " points of damages." << std::endl;
    return this->_melee_attack_damage;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    int damages = amount - this->_armor_damage_reduction;

    if (damages <= 0)
        std::cout << this->_name << "'s armor protected the attack!" << std::endl;
    else if (this->_hit <= damages) {
        this->_hit = 0;
        std::cout << "For few days " << this->_name << " endured terrible pain and died today after a terrible attack..." << std::endl;
    }
    else {
        if (this->_armor_damage_reduction > 0)
            std::cout << "The armor of " << this->_name << " absorbed " << this->_armor_damage_reduction << " attack's points. ";
        std::cout << this->_name << " hit points: " << this->_hit << " -> " << this->_hit - damages << std::endl;
        this->_hit -= damages;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    int total = this->_hit + amount;
    if (total >= this->_max_hit) {
        std::cout << "Magic reparation: " << this->_name << " hit points: " << this->_hit << " -> " << this->_max_hit << std::endl;
        this->_hit = this->_max_hit;
    }
    else {
        std::cout << "Magic reparation: " << this->_name << " hit points: " << this->_hit << " -> " << this->_hit + amount << std::endl;
        this->_hit += amount;        
    }
}


int     ClapTrap::get_hit(void) const {
    return (this->_hit);
}

int     ClapTrap::get_max_hit(void) const {
    return (this->_max_hit);
}

int     ClapTrap::get_energy(void) const {
    return (this->_energy);
}

int     ClapTrap::get_max_energy(void) const {
    return (this->_max_energy);
}

int     ClapTrap::get_level(void) const {
    return (this->_level);
}

std::string ClapTrap::get_name(void) const {
    return (this->_name);
}

int     ClapTrap::get_melee_attack_damage(void) const {
    return (this->_melee_attack_damage);
}

int     ClapTrap::get_ranged_attack_damage(void) const {
    return (this->_ranged_attack_damage);
}

int     ClapTrap::get_armor_damage_reduction(void) const {
    return (this->_armor_damage_reduction);
}
