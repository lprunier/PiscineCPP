/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:31:23 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 17:31:24 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
public	:
	Intern(void);
	~Intern(void);

	Form *	makeForm(std::string const & function, std::string const & target);

	class	CorrectFunction : public	std::exception
	{
	public	:
		CorrectFunction(void);
		CorrectFunction(CorrectFunction const & correctFunction);
		virtual ~CorrectFunction(void) throw();
		CorrectFunction &	operator=(CorrectFunction const & correctfunction);

		const char *	what(void) const throw();
	};

private	:
	Intern(Intern const & intern);
	Intern &	operator=(Intern const & intern);
};

#endif
