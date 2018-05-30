/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:13:19 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 08:13:20 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

const Brain   &Human::getBrain(void) const {
    return this->_jack;
}

std::string Human::identify(void) const {
    return this->_jack.identify();
}
