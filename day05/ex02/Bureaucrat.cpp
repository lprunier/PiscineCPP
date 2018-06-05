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
#include "Form.hpp"

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

void	Bureaucrat::sign_form(Form & form)
{
	try
	{
		if (form.get_requiredSign() > 150)
			throw Form::GradeTooLowException::GradeTooLowException();
		if (form.get_requiredSign() < 1)
			throw Form::GradeTooHighException::GradeTooHighException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	if (this->_grade >= form.get_requiredSign() && !form.get_signed())
	{
		std::cout << this->_name << " signes " << form.get_name() << std::endl;
		form.set_signed();
	}
	else
	{
		std::cout << this->_name << " cannot sign " << form.get_name() << " because ";
		if (this->_grade < form.get_requiredSign() && form.get_signed())
			std::cout << "the bureaucrat's grade is too low and the form is already signed !" << std::endl;
		else if (this->_grade < form.get_requiredSign())
			std::cout << "the Bureaucrat's grade is too low !" << std::endl;
		else
			std::cout << "the form is already signed !" << std::endl;
	}
	return ;
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