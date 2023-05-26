/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:55:36 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 12:17:31 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
	{
        std::cerr << "Error: Unable to open input file." << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
	{
        std::cerr << "Error: Unable to create output file." << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(inputFile, line))
	{
        size_t startPos = 0;
        size_t foundPos;
        while ((foundPos = line.find(s1, startPos)) != std::string::npos)
		{
            outputFile << line.substr(startPos, foundPos - startPos);
            outputFile << s2;
            startPos = foundPos + s1.length();
        }
        outputFile << line.substr(startPos) << std::endl;
	}
    std::cout << "Replacement complete. Output written to " << filename << ".replace" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    // if (s1.empty())
    // {
    //     std::cerr << "Error: s1 can't be empty." << std::endl;
    //     return 1;      
    // }
    std::string s2 = argv[3];

    replaceStringInFile(filename, s1, s2);

    return 0;
}
