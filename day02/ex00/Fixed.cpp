/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:12:36 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 15:12:38 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_value = 0;
    std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
    std::cout << "Copy contructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const &copy )
{
    std::cout << "Assignation operator called" <<std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}