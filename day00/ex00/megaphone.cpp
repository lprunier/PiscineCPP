/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:12:15 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/29 09:12:18 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < ac; ++i)
    {
        for (int j = 0; av[i][j] != '\0'; ++j)
        {
            av[i][j] = toupper(av[i][j]);
            std::cout << av[i][j];
        }
    }

    std::cout << std::endl;
    
    return 0;
}
