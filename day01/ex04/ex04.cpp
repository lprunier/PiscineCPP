/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:00:06 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/30 08:00:07 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {

    std::string str = "HI THIS IS BRAIN";
    std::string *pointer = &str;
    std::string &reference = str;

    std::cout << "Basic string: " << str << std::endl;
    std::cout << "Pointer: " << *pointer << std::endl;
    std::cout << "Reference: " << reference << std::endl;

    return 0;
}
