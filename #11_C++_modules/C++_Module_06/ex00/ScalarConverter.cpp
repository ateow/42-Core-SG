/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:14 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 14:51:22 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <sstream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter& Org) {*this = Org;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& Org){(void) Org; return (*this);}

ScalarConverter::~ScalarConverter(){}

std::string getChar (long intValue, std::string input)
{
    std::string charValue;
    if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
    {
        charValue = input[0];
        charValue = "\'" + charValue + "\'";
    }
    else if (intValue >= 32 && intValue <= 126)
    {
        charValue = static_cast<char>(intValue);
        charValue = "\'" + charValue + "\'";
    }
    else if (input.length() > 1)
        charValue = "\'*\'";
    else
        charValue = "Non Displayable";
    return charValue;
}

void toFloat(std::string input)
{
    std::stringstream ss;

    ss << input;
    float floatValue;
    ss >> floatValue;

    long intValue = static_cast<long>(floatValue);
    std::string charValue = getChar(intValue, input);
    double doubleValue = static_cast<double>(floatValue);

    std::string addzero = "";
    if (intValue == doubleValue)
        addzero = ".0";
    
    // OUTPUT
    std::cout << "char: " << charValue << std::endl;

    if (intValue > 2147483647 || intValue < -2147483648)
    {
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << addzero << "f" << std::endl;
        std::cout << "Double: " << doubleValue << addzero << std::endl;
    }
}

void toDouble(std::string input)
{
    std::stringstream ss;

    ss << input;
    double doubleValue;
    ss >> doubleValue;

    long intValue = static_cast<long>(doubleValue);
    std::string charValue = getChar(intValue, input);
    float floatValue = static_cast<float>(doubleValue);

    std::string addzero = "";
    if (intValue == doubleValue)
        addzero = ".0";
    
    // OUTPUT
    std::cout << "char: " << charValue << std::endl;

    if (intValue > 2147483647 || intValue < -2147483648)
    {
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << addzero << "f" << std::endl;
        std::cout << "Double: " << doubleValue << addzero << std::endl;
    }
}

void toInt(std::string input)
{
    std::stringstream ss;

    ss << input;
    long intValue;
    ss >> intValue;

    std::string charValue = getChar(intValue, input);
    float floatValue = static_cast<float>(intValue);
    double doubleValue = static_cast<double>(intValue);

    std::string addzero = "";
    if (intValue == doubleValue)
        addzero = ".0";
    
    // OUTPUT
    std::cout << "char: " << charValue << std::endl;

    if (intValue > 2147483647 || intValue < -2147483648)
    {
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << addzero << "f" << std::endl;
        std::cout << "Double: " << doubleValue << addzero << std::endl;
    }
}

void toChar(std::string input)
{
    std::string charValue;
    if (input.length() > 1)
    {
        std::cout << "char: " << "\'*\'" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
    }
    else
    {
        std::cout << "char: " << input << std::endl;
        std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
    if (input == "-inf" || input == "+inf" || input == "nan" || input == "-nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input + "f" << std::endl;
        std::cout << "Double: " << input << std::endl;
        return;
    }

    if (isValidFloatLiteral(input) == true)
        toFloat(input);
    else if (isValidDoubleLiteral(input) == true)
        toDouble(input);
    else if (isValidIntLiteral(input) == true)
        toInt(input);
    else
        toChar(input);
}