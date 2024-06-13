/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:07:07 by kali              #+#    #+#             */
/*   Updated: 2024/06/14 02:07:34 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) 
{
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) 
        throw std::runtime_error("Could not open database");        

    std::string line;
    while (std::getline(file, line)) 
    {
        if (line == "date,exchange_rate")
            continue;

        size_t pos = line.find(',');
        if (line.empty() || pos == std::string::npos)
        {
            std::cerr << "Invalid database format: " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pos);
        std::string price = line.substr(pos + 1);

        if (is_valid_date(date) == false)
        {
            std::cerr << "Invalid date format: " << line << std::endl;
            continue;
        }

        if (is_valid_price(price) == false)
        {
            std::cerr << "Invalid price format: " << line << std::endl;
            continue;
        }
    
        
                std::cout << line << std::endl;  // For demonstration, just print each line
    }

    file.close();
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& Org) : price_vector(Org.price_vector), date_vector(Org.date_vector) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& Org) 
{
    if (this != &Org) 
    {
        price_vector = Org.price_vector;
        date_vector = Org.date_vector;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}




bool is_valid_date(const std::string& date) 
{
    // Check if the date string has the correct length
    if (date.length() != 10)
        return false;

    // Check if the date string has the correct format (YYYY-MM-DD)
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) 
        {
            if (date[i] != '-') 
                return false;
        } 
        else 
        {
            if (!std::isdigit(date[i]))
                return false;
        }
    }
    // Extract year, month, and day from the date string
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    // Check if the month is valid
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    
    if (month == 2)
    {
        if (is_leap_year) 
        {
            if (day < 1 || day > 29)
                return false;
        }
        else
        {
            if (day < 1 || day > 28)
                return false;
        }
    }
    return true;
}


bool is_valid_price(const std::string& price) {
    // Check if the string is empty
    if (price.empty())
        return false;

    bool has_decimal_point = false;
    int decimal_places = 0;

    for (size_t i = 0; i < price.length(); ++i) {
        if (price[i] == '.') {
            // Check if there is more than one decimal point
            if (has_decimal_point) {
                return false;
            }
            has_decimal_point = true;
        } else if (!std::isdigit(price[i])) {
            // Check if the character is not a digit
            return false;
        } else if (has_decimal_point) {
            // Count the number of digits after the decimal point
            decimal_places++;
        }
    }

    // If there is a decimal point, it should be followed by exactly two digits
    if (has_decimal_point && decimal_places != 2) {
        return false;
    }

    return true;
}

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
