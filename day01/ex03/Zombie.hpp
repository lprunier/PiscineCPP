/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:07:27 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 17:07:28 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class   Zombie {
public:
    
    Zombie(std::string type, std::string name);
    Zombie(void);
    ~Zombie(void);
    
    std::string type;
    std::string name;

    void    announce(void) const;
};

#endif
