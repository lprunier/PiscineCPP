/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:13:09 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 08:13:11 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>
# include <sstream>

class   Brain {
public:
    Brain(void);
    ~Brain(void);
    std::string think;
    std::string identify(void) const;
};

#endif
