/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:12:34 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/06 17:44:12 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage. ./RPN 1 2 +" << std::endl;
        return 1;
    }

    RPN rpn(argc, argv);
    rpn.calculate();

    return 0;
}
