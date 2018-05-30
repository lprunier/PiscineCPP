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

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int   toInt(void) const;

private:
    int                 _value;
    static const int    _fbits;
};

std::ostream    & operator<<(std::ostream & o, Fixed const & rhs);

#endif
