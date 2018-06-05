/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:55:23 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/04 16:55:25 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) {
    
    Intern	someRandomIntern;
    Form    *rrf;
	Bureaucrat	bureaucrat("Daisy", 1);

	rrf = someRandomIntern.makeForm("robotomy request", "Earth");
	rrf->execute(bureaucrat);
	rrf->be_signed(bureaucrat);
	rrf->execute(bureaucrat);
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Mars");
	rrf->execute(bureaucrat);
	rrf->be_signed(bureaucrat);
	rrf->execute(bureaucrat);
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Uranus");
	rrf->execute(bureaucrat);
	rrf->be_signed(bureaucrat);
	rrf->execute(bureaucrat);
	delete rrf;
	rrf = someRandomIntern.makeForm("random function", "Neptune");

    return 0;
}
