/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:20:59 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:01 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
    this->_name = name;
    this->_weapon = &weapon;
}

void    HumanA::attack(void) const {
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
