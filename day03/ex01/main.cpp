/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:19 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:20 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    srand(time(0));

	FragTrap John("John");
	FragTrap Jack("Jack");
	FragTrap human;

	Jack.takeDamage(John.meleeAttack(Jack.get_name()));
	human.takeDamage(Jack.rangedAttack(human.get_name()));
	Jack.vaulthunter_dot_exe(John.get_name());
	human.vaulthunter_dot_exe(Jack.get_name());
	Jack.vaulthunter_dot_exe(human.get_name());
	John.vaulthunter_dot_exe(Jack.get_name());

	John.beRepaired(12);

	std::cout << John.get_name() << " has " << John.get_hit() << " health left." << std::endl;
	std::cout << Jack.get_name() << " has " << Jack.get_hit() << " health left." << std::endl;
	std::cout << human.get_name() << " has " << human.get_hit() << " health left." << std::endl;


	ScavTrap Kwame("Kwame");
	ScavTrap Donald("Donald");

	Kwame.challengeNewcomer(John.get_name());
	Donald.challengeNewcomer(human.get_name());
	Kwame.challengeNewcomer(Jack.get_name());
	Donald.challengeNewcomer(Kwame.get_name());

	Jack.takeDamage(Kwame.rangedAttack(Jack.get_name()));
	human.vaulthunter_dot_exe(Donald.get_name());
	Kwame.takeDamage(Donald.meleeAttack(Kwame.get_name()));

	std::cout << Jack.get_name() << " has " << Jack.get_hit() << " health left." << std::endl;
	std::cout << John.get_name() << " has " << John.get_hit() << " health left." << std::endl;
	std::cout << human.get_name() << " has " << human.get_hit() << " health left." << std::endl;
	std::cout << Kwame.get_name() << " has " << Kwame.get_hit() << " health left." << std::endl;
	std::cout << Donald.get_name() << " has " << Donald.get_hit() << " health left." << std::endl;

	return 0;
}
