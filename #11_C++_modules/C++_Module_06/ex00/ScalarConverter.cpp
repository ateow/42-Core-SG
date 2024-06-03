/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:14 by kali              #+#    #+#             */
/*   Updated: 2024/06/03 00:29:14 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter& Org) {*this = Org;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& Org){(void) Org; return (*this);}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string input)
{
    bool isPseudoLiteral = (input == "-inf" || input == "+inf" || input == "nan");
    
    // INT
    int intValue = atoi(input.c_str());

    // CHAR:
    std::string charValue;
    if (isPseudoLiteral)
    {
        charValue = "impossible";
    }
    else if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0])) 
    {
        charValue = input[0];
    } 
    else if (intValue >= 0 && intValue <= 127 && isprint(intValue))
    {
        charValue = static_cast<char>(intValue);
    } 
    else if (input.length() > 1)
    {
        charValue = "\'*\'";
    }
    else if (intValue >= 0 && intValue <= 127 && !isprint(intValue))
    {
        charValue = "Non Displayable";
    }

    // FLOAT
    float floatValue;
    floatValue =  atof(input.c_str());
    std::cout << isdigit(input[0]) << std::endl;
    if (isPseudoLiteral) 
    {
        if (input == "-inf") floatValue = -std::numeric_limits<float>::infinity();
        else if (input == "+inf") floatValue = std::numeric_limits<float>::infinity();
        else if (input == "nan") floatValue = std::numeric_limits<float>::quiet_NaN();
    }

    // output:
    std::cout << "char: " << charValue << std::endl;
    if (floatValue == 0 && input != "0")
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << intValue << std::endl;

    // if (floatValue == 0 && input != "0")

    std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;


}        
