/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:14 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:15 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class   ClapTrap {

public:

    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &copy);
    ~ClapTrap(void);
    ClapTrap        &operator=(ClapTrap const &copy);
    unsigned int    rangedAttack(std::string const & target);
    unsigned int    meleeAttack(std::string const & target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

    int         get_hit(void) const;
    int         get_max_hit(void) const;
    int         get_energy(void) const;
    int         get_max_energy(void) const;
    int         get_level(void) const;
    std::string get_name(void) const;
    int         get_melee_attack_damage(void) const;
    int         get_ranged_attack_damage(void) const;
    int         get_armor_damage_reduction(void) const;

protected:

    int         _hit;
    int         _max_hit;
    int         _energy;
    int         _max_energy;
    int         _level;
    std::string _name;
    int         _melee_attack_damage;
    int         _ranged_attack_damage;
    int         _armor_damage_reduction;

};

#endif
