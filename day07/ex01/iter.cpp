/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:40:53 by lprunier          #+#    #+#             */
/*   Updated: 2018/06/07 09:40:56 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template< typename T, typename F >
void    iter( T *array, int len, F function ) {
    for(int i = 0; i < len; i++)
        function(array[i]);
}

void    set_num( int & a ) {
    a = 1;
    std::cout << "Value 1 added in tab." << std::endl;
}

void    up_char( char & c ) {
    std::cout << "Value changed : " << c << " -> ";
    c++;
    std::cout << c << std::endl;
}

void    print_char( char & c ) {
    std::cout << c;
}

void    print_int( int & a ) {
    std::cout << a;
}

int     main( void ) {
    
    int	array[5];
	iter(array, 5, set_num);
    iter(array, 5, print_int);
    std::cout << " " << std::endl << std::endl;

	char hello[] = "Hello world!";
	iter(hello, 12, up_char);
    iter(hello, 12, print_char);
    std::cout << " " << std::endl;
    
    return 0;
}
