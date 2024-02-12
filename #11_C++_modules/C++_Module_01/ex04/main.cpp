/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:36:52 by kali              #+#    #+#             */
/*   Updated: 2024/02/09 03:55:22 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	size_t pos = 0;
	std::string line;

	if (argc != 4)
	{
		std::cout << "invalid args" << std::endl;
		return (1);
	}
	std::ifstream inputFile("input.txt");
	if (!inputFile)
	{
		std::cerr << "Error: Unable to open file for reading" << std::endl;
		return (1);
	}
	std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
	{
        std::cerr << "Error: Unable to create output file: " << filename << ".replace" << std::endl;
        return (1);
    }

	while (std::getline(inputFile, line))
	{
		pos = line.find(s1, pos);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
			pos = line.find(s1, pos);
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}

