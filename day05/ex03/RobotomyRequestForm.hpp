/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:47:55 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:47:56 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class	RobotomyRequestForm : public	Form
{
public	:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const & robotomyRequestForm);
	RobotomyRequestForm(std::string const & target);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm &	operator=(RobotomyRequestForm const & robotomyRequestForm);

	virtual void	execute(Bureaucrat const & executor);

private :
	std::string	_target;
};

#endif
