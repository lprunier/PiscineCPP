/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:14 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:15 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   NinjaTrap : public ClapTrap {

public:

    NinjaTrap(void);
    NinjaTrap(std::string name);
    NinjaTrap(NinjaTrap const &copy);
    ~NinjaTrap(void);
    NinjaTrap        &operator=(NinjaTrap const &copy);

    void    ninjaShoebox(NinjaTrap const &target) const;
    void    ninjaShoebox(ClapTrap const &target) const;
    void    ninjaShoebox(ScavTrap const &target) const;
    void    ninjaShoebox(FragTrap const &target) const;
};

#endif
