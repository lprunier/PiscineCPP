/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:13:01 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 08:13:03 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::string moods [7] = {"happy", "sad", "in love", "hungry", "exited", "stressed", "angry"};
    this->_mood = moods[std::time(NULL) % 7];
}

Brain::~Brain(void) {
}

std::string Brain::identify(void) const {
    const void    *v = static_cast<const void*>(this);
    std::stringstream s;
    s << v;
    return (s.str());
}
