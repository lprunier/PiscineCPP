/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:03:53 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:03:54 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name("\0"), _signed(0), _requiredSign(1), _requiredExecute(1) {
	return	;
}

Form::Form( std::string const & name, int const requiredSign, int const requiredExecute ) :	_name(name),
												_signed(0),
												_requiredSign(requiredSign),
												_requiredExecute(requiredExecute) {
	try {
		if (this->_requiredSign > 150)
			throw Form::GradeTooLowException::GradeTooLowException();
		if (this->_requiredSign < 1)
			throw Form::GradeTooHighException::GradeTooHighException();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		if (this->_requiredExecute > 150)
			throw Form::GradeTooLowException::GradeTooLowException();
		if (this->_requiredExecute < 1)
			throw Form::GradeTooHighException::GradeTooHighException();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(Form const & form) : _requiredSign(1), _requiredExecute(1) {
	*this = form;
}

Form::~Form(void) {
}

Form &	Form::operator=(Form const & form) {
	(void)form;
	return (*this);
}

std::string const &	Form::get_name(void) const {
	return (this->_name);
}

bool		Form::get_signed(void) const {
	return (this->_signed);
}

void		Form::set_signed(void) {
	this->_signed = 1;
}

int		Form::get_requiredSign(void) const {
	return (this->_requiredSign);
}

int		Form::get_requiredExecute(void) const {
	return (this->_requiredExecute);
}

void	Form::be_signed(Bureaucrat const & bureaucrat) {
	try {
		if (bureaucrat.get_grade() > this->_requiredSign)
			throw Form::GradeTooLowException::GradeTooLowException();
		else {
			if (!this->_signed) {
				this->_signed = 1;
				std::cout << bureaucrat.get_name() << " signes " << this->_name << std::endl;
			}
			else
				std::cout << this->_name << " is already signed." << std::endl;
		}	
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

Form::GradeTooHighException::GradeTooHighException(void) {
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & gradeTooHighException) {
	*this = gradeTooHighException;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {
}

Form::GradeTooHighException &	Form::GradeTooHighException::operator=(GradeTooHighException const & gradeTooHighException) {
	(void)gradeTooHighException;
	return (*this);
}

const char *	Form::GradeTooHighException::what(void) const throw() {
	return ("Form grade too high");
}

Form::GradeTooLowException::GradeTooLowException(void) {
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & gradeTooLowException) {
	*this = gradeTooLowException;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {
}

Form::GradeTooLowException &	Form::GradeTooLowException::operator=(GradeTooLowException const & gradeTooLowException) {
	(void)gradeTooLowException;
	return (*this);
}

const char *	Form::GradeTooLowException::what(void) const throw() {
	return ("Form grade too low");
}

std::ostream &	operator<<(std::ostream & o, Form & form) {
	o << form.get_name() << " is ";
	if (!form.get_signed())
		o << "not signed ";
	else
		o << "signed ";
	o << "and needs a grade of " << form.get_requiredSign() << " to be signed ";
	o << "and a grade of " << form.get_requiredExecute() << " to be executed by bureaucrat." << std::endl;
	return (o);
}