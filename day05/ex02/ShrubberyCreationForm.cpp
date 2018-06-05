/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:47:30 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:47:31 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form::Form("Shrubbery creation form", 145, 137), _target("") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :	Form::Form("Shrubbery creation form", 145, 137),
										_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & shrubberyCreationForm) : Form::Form("Shrubbery creation form", 145, 137) {
	*this = shrubberyCreationForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & shrubberyCreationForm) {
	(void)shrubberyCreationForm;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	std::stringstream	str;
	std::ofstream		ofs;

	str << this->_target << "_shrubbery";
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
		ofs.open(str.str());
        ofs << "                                                ." << std::endl;
        ofs << "                                      .         ;  " << std::endl;
        ofs << "         .              .              ;%     ;;   " << std::endl;
        ofs << "           ,           ,                :;%  %;   " << std::endl;
        ofs << "            :         ;                   :;%;'     .,   " << std::endl;
        ofs << "   ,.        %;     %;            ;        %;'    ,;" << std::endl;
        ofs << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        ofs << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
        ofs << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        ofs << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        ofs << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        ofs << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
        ofs << "              `@%:.  :;%.         ;@@%;'   " << std::endl;
        ofs << "                `@%.  `;@%.      ;@@%;         " << std::endl;
        ofs << "                  `@%%. `@%%    ;@@%;        " << std::endl;
        ofs << "                    ;@%. :@%%  %@@%;       " << std::endl;
        ofs << "                      %@bd%%%bd%%:;     " << std::endl;
        ofs << "                        #@%%%%%:;;" << std::endl;
        ofs << "                        %@@%%%::;" << std::endl;
        ofs << "                        %@@@%(o);  . '       " << std::endl;  
        ofs << "                        %@@@o%;:(.,'        " << std::endl; 
        ofs << "                    `.. %@@@o%::;         " << std::endl;
        ofs << "                       `)@@@o%::;         " << std::endl;
        ofs << "                        %@@(o)::;        " << std::endl;
        ofs << "                       .%@@@@%::;         " << std::endl;
        ofs << "                       ;%@@@@%::;.        " << std::endl;  
        ofs << "                      ;%@@@@%%:;;;. " << std::endl;
        ofs << "                  ...;%@@@@@%%:;;;;,.." << std::endl;
		ofs.close();
		std::cout << "A shrubbery has been planted in " << this->_target << std::endl;
	}
	return ;
}
