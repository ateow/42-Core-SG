/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:10 by kali              #+#    #+#             */
/*   Updated: 2024/06/01 22:49:48 by kali             ###   ########.fr       */
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

#endif