/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:11:50 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 18:11:51 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
    this->_len = n;
    this->_horde = new Zombie[n];
}

ZombieHorde::~ZombieHorde(void) {
    delete [] this->_horde;
}

void    ZombieHorde::announce(void) const {
    for (int i = 0; i < this->_len; i++) {
        this->_horde[i].announce();
    }
}
