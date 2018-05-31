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

int main(void) {

    FragTrap    One("First");
    FragTrap    Two("Second");

    Two.takeDamage(One.rangedAttack(Two.get_name()));
    One.takeDamage(Two.meleeAttack(One.get_name()));

    return 0;
}
