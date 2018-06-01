/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:10 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:11 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    this->_hit = 100;
    this->_max_hit = 100;
    this->_energy = 50;
    this->_max_energy = 50;
    this->_level = 1;
    this->_name = "no name";
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
    this->_armor_damage_reduction = 3;
    std::cout << "A new scavtrap " << this->_name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name) {
    this->_hit = 100;
    this->_max_hit = 100;
    this->_energy = 50;
    this->_max_energy = 50;
    this->_level = 1;
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
    this->_armor_damage_reduction = 3;
    std::cout << "A new scavtrap " << this->_name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) {
    std::cout << copy._name << " is cloned." << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap(void) {
    std::cout << this->_name << " has disappeared!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy) {
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


unsigned int    ScavTrap::rangedAttack(std::string const & target) {
    std::cout << this->_name << " attaks " << target << " at range causing " << this->_ranged_attack_damage << " points of damages." << std::endl;
    return this->_ranged_attack_damage;
}

unsigned int    ScavTrap::meleeAttack(std::string const & target) {
    std::cout << this->_name << " attaks " << target << " at melee causing " << this->_melee_attack_damage << " points of damages." << std::endl;
    return this->_melee_attack_damage;
}

void    ScavTrap::takeDamage(unsigned int amount) {
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

void    ScavTrap::beRepaired(unsigned int amount) {
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


int     ScavTrap::get_hit(void) const {
    return (this->_hit);
}

int     ScavTrap::get_max_hit(void) const {
    return (this->_max_hit);
}

int     ScavTrap::get_energy(void) const {
    return (this->_energy);
}

int     ScavTrap::get_max_energy(void) const {
    return (this->_max_energy);
}

int     ScavTrap::get_level(void) const {
    return (this->_level);
}

std::string ScavTrap::get_name(void) const {
    return (this->_name);
}

int     ScavTrap::get_melee_attack_damage(void) const {
    return (this->_melee_attack_damage);
}

int     ScavTrap::get_ranged_attack_damage(void) const {
    return (this->_ranged_attack_damage);
}

int     ScavTrap::get_armor_damage_reduction(void) const {
    return (this->_armor_damage_reduction);
}

void    ScavTrap::celebrate(std::string const &target){
    std::cout << this->_name << " challenge " << target << " to sing the celebrate song!" << std::endl;
    this->_energy -= 25;
}

void    ScavTrap::camouflage(std::string const &target){
    std::cout << this->_name << " challenge " << target << " to camoufle himself... " << std::endl;
    this->_energy -= 25;
}

void    ScavTrap::lucky_song(std::string const &target){
    std::cout << this->_name << " challenge " << target << " to write a lucky song." << std::endl;
    this->_energy -= 25;
}

void    ScavTrap::natural_gift(std::string const &target){
    std::cout << this->_name << " challenge " << target << " to do a natural gift made with love... So cute!" << std::endl;
    this->_energy -= 25;
}

void    ScavTrap::puzzle(std::string const &target){
    std::cout << this->_name << " challenge " << target << " to resolve this puzzle! So hard!" << std::endl;
    this->_energy -= 25;
}

void    ScavTrap::challengeNewcomer(std::string const &target)
{
	int		index;
	void	(ScavTrap::*challenges[5])(std::string const &target);

	challenges[0] = &ScavTrap::celebrate;
	challenges[1] = &ScavTrap::camouflage;
	challenges[2] = &ScavTrap::lucky_song;
	challenges[3] = &ScavTrap::natural_gift;
	challenges[4] = &ScavTrap::puzzle;

	index = rand() % 5;
	if (this->_energy >= 25)
		(this->*challenges[index])(target);
	else
		std::cout << this->_name << " doesn't have enough energy !" << std::endl;
	return ;
}
