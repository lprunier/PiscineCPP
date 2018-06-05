/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:03:59 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/05 14:04:00 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
public	:
	Form(void);
	Form(Form const & form);
	Form(std::string const & name, int const requiredSign, int const requiredExecute);
	virtual ~Form(void);

	Form &	operator=(Form const & form);

	std::string const &	get_name(void) const;
	bool	get_signed(void) const;
	void	set_signed(void);
	int		get_requiredSign(void) const;
	int		get_requiredExecute(void) const;
	void	be_signed(Bureaucrat const & bureaucrat);
	virtual void	execute(Bureaucrat const & executor) = 0;

	class	GradeTooHighException : public	std::exception
	{
	public	:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & gradeTooHighException);
		virtual	~GradeTooHighException(void) throw();
		GradeTooHighException &	operator=(GradeTooHighException const & gradeTooHighException);

		virtual const char *	what(void) const throw();
	};

	class	GradeTooLowException : public	std::exception
	{
	public	:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & gradeTooLowException);
		virtual	~GradeTooLowException(void) throw();
		GradeTooLowException &	operator=(GradeTooLowException const & gradeTooLowException);

		virtual const char *	what(void) const throw();
	};

private	:

	std::string const	_name;
	bool		_signed;
	int const	_requiredSign;
	int const	_requiredExecute;
};

std::ostream &	operator<<(std::ostream & o, Form & form);


#endif
