/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:11:56 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 18:11:57 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class   ZombieHorde {
public:
    ZombieHorde(int n);
    ~ZombieHorde(void);
    void    announce(void) const ;

private:
    Zombie  *_horde;
    int     _len;
};

#endif
