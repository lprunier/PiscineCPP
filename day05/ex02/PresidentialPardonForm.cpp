/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:48:08 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:48:09 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form::Form("Presidential pardon form", 25, 5), _target("") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :	Form::Form("Presidential pardon form", 145, 137),
										_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & presidentialPardonForm) : Form::Form("Presidential pardon form", 145, 137) {
	*this = presidentialPardonForm;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & presidentialPardonForm) {
	(void)presidentialPardonForm;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) {
	if (!this->get_signed() || executor.get_grade() > this->get_requiredExecute()) {
		std::cout << executor.get_name() << " cannot execute " << this->get_name() << " because ";
		if (!this->get_signed() && executor.get_grade() > this->get_requiredExecute()) {
			std::cout << "the form isn't signed and the bureaucrat has a grade lower ";
			std::cout << "than the required grade asked by the form" << std::endl;
		}
		else if (!this->get_signed())
			std::cout << "the form isn't signed" << std::endl;
		else
			std::cout << "the bureaucrat has a grade lower than the required grade asked by the form" << std::endl;
		return ;
	}
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}
