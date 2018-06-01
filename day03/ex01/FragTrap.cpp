/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:10 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:11 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    this->_hit = 100;
    this->_max_hit = 100;
    this->_energy = 100;
    this->_max_energy = 100;
    this->_level = 1;
    this->_name = "no name";
    this->_melee_attack_damage = 30;
    this->_ranged_attack_damage = 20;
    this->_armor_damage_reduction = 5;
    std::cout << "A new " << this->_name << " is born!" << std::endl;
}

FragTrap::FragTrap(std::string name) : _name(name) {
    this->_hit = 100;
    this->_max_hit = 100;
    this->_energy = 100;
    this->_max_energy = 100;
    this->_level = 1;
    this->_melee_attack_damage = 30;
    this->_ranged_attack_damage = 20;
    this->_armor_damage_reduction = 5;
    std::cout << "A new " << this->_name << " is born!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) {
    std::cout << copy._name << " is cloned." << std::endl;
    *this = copy;
}

FragTrap::~FragTrap(void) {
    std::cout << this->_name << " has disappeared!" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy) {
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


unsigned int    FragTrap::rangedAttack(std::string const & target) {
    std::cout << this->_name << " attaks " << target << " at range causing " << this->_ranged_attack_damage << " points of damages." << std::endl;
    return this->_ranged_attack_damage;
}

unsigned int    FragTrap::meleeAttack(std::string const & target) {
    std::cout << this->_name << " attaks " << target << " at melee causing " << this->_melee_attack_damage << " points of damages." << std::endl;
    return this->_melee_attack_damage;
}

void    FragTrap::takeDamage(unsigned int amount) {
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

void    FragTrap::beRepaired(unsigned int amount) {
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


int     FragTrap::get_hit(void) const {
    return (this->_hit);
}

int     FragTrap::get_max_hit(void) const {
    return (this->_max_hit);
}

int     FragTrap::get_energy(void) const {
    return (this->_energy);
}

int     FragTrap::get_max_energy(void) const {
    return (this->_max_energy);
}

int     FragTrap::get_level(void) const {
    return (this->_level);
}

std::string FragTrap::get_name(void) const {
    return (this->_name);
}

int     FragTrap::get_melee_attack_damage(void) const {
    return (this->_melee_attack_damage);
}

int     FragTrap::get_ranged_attack_damage(void) const {
    return (this->_ranged_attack_damage);
}

int     FragTrap::get_armor_damage_reduction(void) const {
    return (this->_armor_damage_reduction);
}

void    FragTrap::baby_dolls_eyes(std::string const &target){
    std::cout << this->_name << " uses Baby_dolls Eyes on " << target << "... Beautifuls eyes baby!" << std::endl;
    this->_energy -= 25;
}

void    FragTrap::bubble(std::string const &target){
    std::cout << this->_name << " uses Bubble on " << target << "... It's rainning bubbles now :)" << std::endl;
    this->_energy -= 25;
}

void    FragTrap::metronome(std::string const &target){
    std::cout << this->_name << " uses Metronome on " << target << "... You can use it, INCREDIBLE!!" << std::endl;
    this->_energy -= 25;
}

void    FragTrap::magic_coat(std::string const &target){
    std::cout << this->_name << " uses Magic coat on " << target << "... Incredible style!" << std::endl;
    this->_energy -= 25;
}

void    FragTrap::splash(std::string const &target){
    std::cout << this->_name << " uses Splash on " << target << "... Wow water..." << std::endl;
    this->_energy -= 25;
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int		index;
	void	(FragTrap::*attacks[5])(std::string const &target);

	attacks[0] = &FragTrap::baby_dolls_eyes;
	attacks[1] = &FragTrap::bubble;
	attacks[2] = &FragTrap::metronome;
	attacks[3] = &FragTrap::magic_coat;
	attacks[4] = &FragTrap::splash;

	index = rand() % 5;
	if (this->_energy >= 25)
		(this->*attacks[index])(target);
	else
		std::cout << this->_name << " doesn't have enough energy !" << std::endl;
	return ;
}