/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:01:21 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:02:29 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* strPtr = &str;
	std::string& strRef = str;

	std::cout << "Dirección de memoria de la variable de tipo string: " << &str << std::endl;
	std::cout << "Dirección de memoria contenida en stringPTR: " << strPtr << std::endl;
	std::cout << "Dirección de memoria contenida en stringREF: " << &strRef << std::endl;

	std::cout << "Valor de la variable string: " << str << std::endl;
	std::cout << "Valor apuntado por stringPTR: " << *strPtr << std::endl;
	std::cout << "Valor apuntado por stringREF: " << strRef << std::endl;

	return 0;
}
