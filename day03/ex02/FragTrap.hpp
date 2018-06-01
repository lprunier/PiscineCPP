/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:57:14 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/31 11:57:15 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class   FragTrap : public ClapTrap {

public:

    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(FragTrap const &copy);
    ~FragTrap(void);
    FragTrap        &operator=(FragTrap const &copy);

    void        baby_dolls_eyes(std::string const &target);
    void        bubble(std::string const &target);
    void        metronome(std::string const &target);
    void        magic_coat(std::string const &target);
    void        splash(std::string const &target);
    void        vaulthunter_dot_exe(std::string const &target);

};

#endif
