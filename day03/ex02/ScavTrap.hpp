/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:14 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:15 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap {

public:

    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &copy);
    ~ScavTrap(void);
    ScavTrap        &operator=(ScavTrap const &copy);

    void        camouflage(std::string const &target);
    void        celebrate(std::string const &target);
    void        lucky_song(std::string const &target);
    void        natural_gift(std::string const &target);
    void        puzzle(std::string const &target);
    void        challengeNewcomer(std::string const &target);

};

#endif
