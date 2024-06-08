/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:31 by ateow             #+#    #+#             */
/*   Updated: 2024/06/08 14:51:32 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SCALARCONVERTER_HPP_
# define _SCALARCONVERTER_HPP_

# include <iostream>
# include <exception>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <string>

class ScalarConverter
{
    private:
        // constructor
        ScalarConverter();

        // copy constructor
        ScalarConverter(ScalarConverter& Org);

        // copy operator assign
        ScalarConverter& operator=(ScalarConverter& Org);
    
    public:

        // destructor
        ~ScalarConverter();
       
        static void convert(std::string input);
};

bool isValidFloatLiteral(const std::string& str);
bool isValidDoubleLiteral(const std::string& str);
bool isValidIntLiteral(const std::string& str);

#endif