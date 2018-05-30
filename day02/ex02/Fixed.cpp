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

const int	Fixed::_fbits = 8;

Fixed::Fixed(void) {
    // std::cout << "Default contructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(Fixed const &copy) {
    // std::cout << "Copy contructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const i) {
    // std::cout << "Int contructor called" << std::endl;
    this->_value = i << Fixed::_fbits;
}

Fixed::Fixed(float const f) {
    // std::cout << "Float contructor called" << std::endl;
    this->_value = roundf(f * (1 << Fixed::_fbits));
}

Fixed::~Fixed(void) {
    // std::cout << "Destructor called" << std::endl;
}



///////////////////////////Operators/////////////////////////////////

Fixed	&Fixed::operator=(Fixed const &copy) {
    // std::cout << "Assignation operator called" <<std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

Fixed   Fixed::operator+(Fixed const &copy) const {
    return (this->toFloat() + copy.toFloat());
}

Fixed   Fixed::operator-(Fixed const &copy) const {
    return (this->toFloat() - copy.toFloat());
}

Fixed   Fixed::operator*(Fixed const &copy) const {
    return (this->toFloat() * copy.toFloat());
}

Fixed   Fixed::operator/(Fixed const &copy) const {
    return (this->toFloat() / copy.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

bool   Fixed::operator>(Fixed const &copy) const {
    return (this->_value > copy.getRawBits());
}

bool   Fixed::operator<(Fixed const &copy) const {
    return (this->_value < copy.getRawBits());
}

bool   Fixed::operator>=(Fixed const &copy) const {
    return (this->_value >= copy.getRawBits());
}

bool   Fixed::operator<=(Fixed const &copy) const {
    return (this->_value <= copy.getRawBits());
}

bool   Fixed::operator==(Fixed const &copy) const {
    return (this->_value == copy.getRawBits());
}

bool   Fixed::operator!=(Fixed const &copy) const {
    return (this->_value != copy.getRawBits());
}

/////////////////////////////////////////////////////////////////////



int     Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void    Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float   Fixed::toFloat(void) const {
    return this->_value / (float)(1 << Fixed::_fbits);
}

int   Fixed::toInt(void) const {
    return this->_value / (1 << Fixed::_fbits);
}

std::ostream    & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return o;
}
