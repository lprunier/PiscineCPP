/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:21:16 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:16 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->_name = name;
}

void    HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void    HumanB::attack(void) const {
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

