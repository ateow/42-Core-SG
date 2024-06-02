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

}        
