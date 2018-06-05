/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:55:36 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/04 16:55:37 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class   Bureaucrat {
public:

    Bureaucrat( void );
    Bureaucrat( std::string name, int grade );
    Bureaucrat( Bureaucrat const & copy );
    virtual ~Bureaucrat( void );

    Bureaucrat  & operator=( Bureaucrat const & copy );

    std::string get_name( void ) const;
    int         get_grade( void ) const;
    void	    increment_grade(void);
	void	    decrement_grade(void);
	void		sign_form(Form & form);

	class	GradeTooHighException : public	std::exception
	{
	public	:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & gradeTooHighException);
		virtual ~GradeTooHighException(void) throw();
		GradeTooHighException &	operator=(GradeTooHighException const & gradeTooHighException);

		virtual const char *	what(void) const throw();
	};

	class	GradeTooLowException : public	std::exception
	{
	public	:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & gradeTooLowException);
		virtual ~GradeTooLowException(void) throw();
		GradeTooLowException &	operator=(GradeTooLowException const & gradeTooLowException);

		virtual const char *	what(void) const throw();
	};


private:

    std::string _name;
    int         _grade;

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif
