/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:07:44 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 17:07:45 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class   ZombieEvent {
public:
    void    setZombieType(std::string type);
    Zombie  *newZombie(std::string name);
    void    randomChump(void);
private:
    std::string _type;
};

#endif
