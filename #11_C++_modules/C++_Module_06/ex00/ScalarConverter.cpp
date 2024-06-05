/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:14 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 21:31:19 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <unistd.h>
#include <limits>
#include <sstream>
#include <iostream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter& Org) {*this = Org;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& Org){(void) Org; return (*this);}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string input)
{
    bool isPseudoLiteral = (input == "-inf" || input == "+inf" || input == "nan");
    if (isPseudoLiteral == true)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input + "f" << std::endl;
        std::cout << "Double: " << input << std::endl;
        return;
    }


    // INT
    std::stringstream ss;
    ss << input;
    long intValue;
    ss >> intValue;
    // std::cout << intValue << std::endl;
    
    // CHAR:
    std::string charValue;
    if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0])) 
    {
        charValue = input[0];
    } 
    else if (intValue >= 32 && intValue <= 126)
    {
        charValue = static_cast<char>(intValue);
    } 
    else if (input.length() > 1)
    {
        charValue = "\'*\'";
    }
    else if (!isprint(intValue))
    {
        charValue = "Non Displayable";
    }


    // FLOAT
    std::stringstream ss2;

    ss2 << input;
    float floatValue;
    ss2 >> floatValue;
    floatValue = static_cast<float>(floatValue);

    // DOUBLE
    std::stringstream ss3;
    ss3 << input;
    double doubleValue;
    ss3 >> doubleValue;
    doubleValue = static_cast<double>(doubleValue);
    std::cout << doubleValue << "," << std::numeric_limits<double>::min() << std::endl;
    if (std::numeric_limits<double>::min() > 0)
        std::cout << "here\n" << std::endl;

    // OUTPUT
    std::cout << "char: " << charValue << std::endl;

    if (!isValidIntLiteral(input) and !isValidFloatLiteral(input) and !isValidDoubleLiteral(input))
        std::cout << "int: impossible" << std::endl;
    else if (intValue > 2147483647 || intValue < -2147483648)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << intValue << std::endl;


    if (!isValidIntLiteral(input) and !isValidFloatLiteral(input) and !isValidDoubleLiteral(input))
        std::cout << "float: impossible" << std::endl;
    else if (floatValue <= std::numeric_limits<float>::min() || floatValue >= std::numeric_limits<float>::max())
        std::cout << "float: impossible!" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;



    if (!isValidIntLiteral(input) and !isValidFloatLiteral(input) and !isValidDoubleLiteral(input))
        std::cout << "Double: impossible" << std::endl;
    else if (doubleValue >= std::numeric_limits<double>::min() || doubleValue >= std::numeric_limits<double>::max())
        std::cout << "Double: impossible!" << std::endl;
    else
        std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}
