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

class   Bureaucrat {
public:

    Bureaucrat( void );
    Bureaucrat( Bureaucrat const & copy );
    ~Bureaucrat( void );

    Bureaucrat  & operator=( Bureaucrat const & copy );

    std::string get_name( void ) const;
    int         get_grade( void ) const;

private:

    std::string _name;
    int         _grade;

};

#endif
