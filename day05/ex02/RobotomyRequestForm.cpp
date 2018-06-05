/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:47:49 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:47:50 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form::Form("Robotomy request form", 72, 45), _target("") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :	Form::Form("Robotomy request form", 72, 45),
									_target(target) {
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & robotomyRequestForm) : Form::Form("Robotomy request form", 145, 137) {
	*this = robotomyRequestForm;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & robotomyRequestForm) {
	(void)robotomyRequestForm;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) {
	int	random;

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
	else {
		random = std::rand() % 2;
		if (!random)
			std::cout << "The robotomy of " << this->_target << " has failed" << std::endl;
		else
			std::cout << this->_target << " has been robotomized succesfully" << std::endl;
	}
	return ;
}