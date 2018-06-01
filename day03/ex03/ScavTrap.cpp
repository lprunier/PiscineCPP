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

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->_energy = 50;
    this->_max_energy = 50;
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
    this->_armor_damage_reduction = 3;
    std::cout << "And it is a ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_energy = 50;
    this->_max_energy = 50;
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
    this->_armor_damage_reduction = 3;
    std::cout << "And it is a ScavTrap." << std::endl;
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
