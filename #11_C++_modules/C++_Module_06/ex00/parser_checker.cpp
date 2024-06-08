/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:17 by ateow             #+#    #+#             */
/*   Updated: 2024/06/08 17:27:28 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

bool isValidFloatLiteral(const std::string& str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    bool hasDecimal = false;
    if (str[i] == '-' || str[i] == '+')
        i++; // Skip optional sign
    while (i < str.size() - 1) 
    {
        if (str[i] == '.') 
        {
            if (hasDecimal) 
                return false;
            hasDecimal = true;
        } 
        else if (!isdigit(str[i])) 
            return false;
        i++;
    }
    if (str[i] != 'f')
        return false;
    return true;
}

bool isValidDoubleLiteral(const std::string& str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    bool hasDecimal = false;
    if (str[i] == '-' || str[i] == '+')
        i++; // Skip optional sign
    while (i < str.size()) 
    {
        if (str[i] == '.') 
        {
            if (hasDecimal) 
                return false;
            hasDecimal = true;
        } 
        else if (!isdigit(str[i])) 
            return false;
        i++;
    }
    if (hasDecimal != true)
        return false;
    return true;
}

bool isValidIntLiteral(const std::string& str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++; // Skip optional sign
    if (i == str.size())
        return false;
    while (i < str.size()) 
    {
        if (!isdigit(str[i])) 
            return false;
        i++;
    }
    return true;
}
