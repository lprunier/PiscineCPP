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

FragTrap::FragTrap(void) : ClapTrap() {
    this->_energy = 100;
    this->_max_energy = 100;
    this->_melee_attack_damage = 30;
    this->_ranged_attack_damage = 20;
    this->_armor_damage_reduction = 5;
    std::cout << "And it is a FragTrap." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_energy = 100;
    this->_max_energy = 100;
    this->_melee_attack_damage = 30;
    this->_ranged_attack_damage = 20;
    this->_armor_damage_reduction = 5;
    std::cout << "And it is a FragTrap." << std::endl;
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