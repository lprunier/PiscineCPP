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

int main( void ) {
    
    Bureaucrat  b = Bureaucrat("First player", 800);
    std::cout << b;
    b.decrement_grade();
    std::cout << b << std::endl;

    Bureaucrat  c = Bureaucrat("Second player", 9);
    std::cout << c;
    c.increment_grade();
    c.increment_grade();
    c.increment_grade();
    std::cout << c << std::endl;
    
    Bureaucrat  d = Bureaucrat("Third player", 0);
    std::cout << d;
    d.decrement_grade();
    std::cout << d << std::endl;
    
	Form    form1("Form-AX-16", 0, 151);
	Form	form2("Form-PG-197", 151, 0);
	Form	form3("Form-IO-43", 149, 150);
    Form	form4("Form-GS-98", 150, 1);
    
	std::cout << form1;
	std::cout << form2;
	std::cout << form3;
	form1.be_signed(b);
	form3.be_signed(b);
	form4.be_signed(c);
	form4.be_signed(d);
	d.sign_form(form3);
    b.increment_grade();
	c.sign_form(form3);
	std::cout << c << std::endl;

    ShrubberyCreationForm   form5 = ShrubberyCreationForm("Mars");

    form5.execute(d);
	form5.be_signed(d);
    form5.execute(d);
    
    RobotomyRequestForm form6 = RobotomyRequestForm("Earth");

    form6.execute(d);
	form6.be_signed(d);
	form6.execute(d);

    PresidentialPardonForm form7 = PresidentialPardonForm("Venus");

    form7.execute(d);
	form7.be_signed(d);
	form7.execute(d);
    
    return 0;
}
