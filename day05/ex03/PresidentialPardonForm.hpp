/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:48:13 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:48:15 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <sstream>

class	PresidentialPardonForm : public	Form
{
public	:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const & presidentialParodonForm);
	PresidentialPardonForm(std::string const & target);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm &	operator=(PresidentialPardonForm const & presidentialPardonForm);

	virtual void	execute(Bureaucrat const & executor);

private :
	std::string	_target;
};

#endif
