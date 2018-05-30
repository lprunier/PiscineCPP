/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:13:27 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 08:13:29 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class   Human {
public:
    const Brain       &getBrain(void) const;
    std::string identify(void) const;

private:
    const Brain   _jack;

};

#endif
