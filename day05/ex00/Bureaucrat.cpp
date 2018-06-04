/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:55:40 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/04 16:55:43 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(0) {
}

Bureaucrat::Bureaucrat( Bureaucrat const & copy ) {
    *this = copy;
}

Bureaucrat::~Bureaucrat( void ) {
}

Bureaucrat  & Bureaucrat::operator=( Bureaucrat const & copy ) {
    this->_name = copy.get_name();
    this->_grade = copy.get_grade();
    return *this;
}

std::string Bureaucrat::get_name( void ) const {
    return ( this->_name );
}

int Bureaucrat::get_grade(void) const {
    return ( this->_grade );
}