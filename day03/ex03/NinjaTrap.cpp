/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:10 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:11 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap() {
    this->_hit = 60;
    this->_max_hit = 60;
    this->_energy = 120;
    this->_max_energy = 120;
    this->_melee_attack_damage = 60;
    this->_ranged_attack_damage = 5;
    this->_armor_damage_reduction = 0;
    std::cout << "And it is a NinjaTrap." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) {
    this->_hit = 60;
    this->_max_hit = 60;
    this->_energy = 120;
    this->_max_energy = 120;
    this->_melee_attack_damage = 60;
    this->_ranged_attack_damage = 5;
    this->_armor_damage_reduction = 0;
    std::cout << "And it is a NinjaTrap." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &copy) {
    std::cout << copy._name << " is cloned." << std::endl;
    *this = copy;
}

NinjaTrap::~NinjaTrap(void) {
    std::cout << this->_name << " has disappeared!" << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &copy) {
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

void    NinjaTrap::ninjaShoebox(NinjaTrap const &target) const {
    std::cout << this->_name << " meet " << target.get_name() << " and does some Ninja's things with him." << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap const &target) const {
    std::cout << this->_name << " meet " << target.get_name() << " and look at the clouds with him." << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap const &target) const {
    std::cout << this->_name << " meet " << target.get_name() << "... " << this->_name << " doesn't like " << target.get_name() << "." << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap const &target) const {
    std::cout << this->_name << " meet " << target.get_name() << " with smile." << std::endl;
}
