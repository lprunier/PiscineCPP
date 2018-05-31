/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:12:41 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 15:12:42 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class   Fixed {
public:
    Fixed(void);
    Fixed(Fixed const &copy);
    Fixed(int const i);
    Fixed(float const f);
    ~Fixed(void);

    Fixed   & operator=(Fixed const &copy);

    Fixed   operator+(Fixed const &copy) const;
    Fixed   operator-(Fixed const &copy) const;
    Fixed   operator*(Fixed const &copy) const;
    Fixed   operator/(Fixed const &copy) const;
    Fixed	&operator++(void);
    Fixed	operator++(int);    
    Fixed	&operator--(void);
    Fixed	operator--(int);    
    bool    operator>(Fixed const &copy) const;
    bool    operator<(Fixed const &copy) const;
    bool    operator>=(Fixed const &copy) const;
    bool    operator<=(Fixed const &copy) const;
    bool    operator==(Fixed const &copy) const;
    bool    operator!=(Fixed const &copy) const;


    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    static Fixed &min(Fixed & a, Fixed & b);
	static Fixed const 	& min(Fixed const & a, Fixed const & b);
	static Fixed &max(Fixed & a, Fixed & b);
	static Fixed const 	& max(Fixed const & a, Fixed const & b);

private:
    int                 _value;
    static const int    _fbits;
};

std::ostream    & operator<<(std::ostream & o, Fixed const & rhs);

#endif
