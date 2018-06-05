/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:31:30 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 17:31:31 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::Intern(Intern const & intern) {
	*this = intern;
}

Intern::~Intern(void) {
}

Intern &	Intern::operator=(Intern const & intern) {
	(void)intern;
	return (*this);
}

Form *	Intern::makeForm(std::string const & function, std::string const & target) {
	try {
		if (!function.compare("shrubbery creation"))
			return (new ShrubberyCreationForm(target));
		if (!function.compare("robotomy request"))
			return (new RobotomyRequestForm(target));
		if (!function.compare("presidential pardon"))
			return (new PresidentialPardonForm(target));
		throw CorrectFunction::CorrectFunction();
	}
	catch (std::exception &e) {
		std::cerr << e.what () << std::endl;
	}
	return (NULL);
}

Intern::CorrectFunction::CorrectFunction(void) {
}

Intern::CorrectFunction::CorrectFunction(CorrectFunction const & correctFunction) {
	*this = correctFunction;
}

Intern::CorrectFunction::~CorrectFunction(void) throw() {
}

Intern::CorrectFunction &	Intern::CorrectFunction::operator=(CorrectFunction const & correctFunction) {
	(void)correctFunction;
	return (*this);
}

const char *	Intern::CorrectFunction::what(void) const throw() {
	return ("Incorrect function name");
}
