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

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {

    try {
		if (this->_grade < 1) {
			this->_grade = 1;
			throw Bureaucrat::GradeTooLowException::GradeTooLowException();
		}
		if (this->_grade > 150) {
			this->_grade = 150;
			throw Bureaucrat::GradeTooHighException::GradeTooHighException();
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return ;

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

void    Bureaucrat::increment_grade( void ) {
    this->_grade++;

    try {
		if (this->_grade > 150) {
			this->_grade = 150;
			throw Bureaucrat::GradeTooHighException::GradeTooHighException();
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

}

void    Bureaucrat::decrement_grade( void ) {
    this->_grade--;

    try {
		if (this->_grade < 1) {
			this->_grade = 1;
			throw Bureaucrat::GradeTooLowException::GradeTooLowException();
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

}


/***** GradeTooHighException *****/

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {
}

Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const & gradeTooHighException) {
    *this = gradeTooHighException;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {
}

Bureaucrat::GradeTooHighException &	Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & gradeTooHighException) {
	(void)gradeTooHighException;
	return (*this);
}

const char *	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}


/***** GradeTooLowException *****/

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {
}

Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const & gradeTooLowException) {
    *this = gradeTooLowException;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {
}

Bureaucrat::GradeTooLowException &	Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & gradeTooLowException) {
	(void)gradeTooLowException;
	return (*this);
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}



std::ostream &	operator<<(std::ostream & o, Bureaucrat const & bureaucrat)
{
	o << "Name: " << bureaucrat.get_name() << " -  Grade: " << bureaucrat.get_grade() << std::endl;
	return (o);
}