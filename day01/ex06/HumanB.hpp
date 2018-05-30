/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:21:21 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:24 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class   HumanB {
public:
    HumanB(std::string name);
    void    setWeapon(Weapon &weapon);
    void    attack(void) const;

private:
    std::string _name;
    Weapon      *_weapon;

};

#endif
