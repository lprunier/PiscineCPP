/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:12:00 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 18:12:02 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void) {
    std::cout << "BORN OF THE HORDE!" << std::endl;
	ZombieHorde horde = ZombieHorde(10);
	std::cout << "__________________" << std::endl;
	horde.announce();
	std::cout << "AND THE END..." << std::endl;
}
