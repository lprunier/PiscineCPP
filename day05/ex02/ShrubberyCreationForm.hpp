/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:47:36 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:47:39 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <sstream>

class	ShrubberyCreationForm : public Form
{
public	:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const & shrubberyCreationForm);
	ShrubberyCreationForm(std::string const & target);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & shrubberyCreationForm);

	virtual void	execute(Bureaucrat const & executor);

private :
	std::string	_target;
};

#endif
