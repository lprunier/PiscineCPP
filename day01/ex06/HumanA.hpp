/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:21:07 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:08 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class   HumanA {
public:
    HumanA(std::string name, Weapon &weapon);
    void    attack(void) const;

private:
    std::string _name;
    Weapon      *_weapon;

};

#endif
