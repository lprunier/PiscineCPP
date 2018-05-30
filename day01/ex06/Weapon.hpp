/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:21:36 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:37 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class   Weapon {
public:
    Weapon(std::string type);
    void        setType(std::string type);
    std::string getType(void) const;

private:
    std::string _type;
};

#endif
