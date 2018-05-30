/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:21:30 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:32 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->_type = type;
}

void    Weapon::setType(std::string type) {
    this->_type = type;
}

std::string Weapon::getType(void) const {
    return(this->_type);
}
