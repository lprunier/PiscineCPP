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
    std::cout << d;
    
    return 0;
}
