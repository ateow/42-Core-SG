/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:07:07 by kali              #+#    #+#             */
/*   Updated: 2024/06/16 13:55:37 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) 
{
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) 
        throw std::runtime_error("Error: could not open database");        

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
        
        bool is_duplicate = false;
        for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); ++it)
        {
            if (it->first == date) {
                std::cerr << "Duplicate date found: " << date << std::endl;
                is_duplicate = true;
                break;
            }
        }
        if (is_duplicate)
            continue;
            
        std::stringstream ss(price);
        float result;
        ss >> result;

        map.insert(std::make_pair(date, result));
    }
    file.close();
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& Org) : map(Org.map) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& Org) 
{
    if (this != &Org) 
    {
        map = Org.map;
        // price_vector = Org.price_vector;
        // date_vector = Org.date_vector;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::compute(std::string filename)
{
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) 
        throw std::runtime_error("Error: could not open input file");        

    std::string line;
    while (std::getline(file, line)) 
    {
        
        if (line == "date | value")
            continue;

        size_t pos = line.find('|');
        if (line.empty() || pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (pos != 11 || line.substr(10, 3) != " | ")
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        
        std::string date = line.substr(0, pos - 1);
        std::string value = line.substr(pos + 2);

        if (is_valid_date(date) == false)
        {
            std::cerr << "Error: Invalid input date format: " << line << std::endl;
            continue;
        }

        std::stringstream ss(value);
        float result;
        ss >> result;
        if (result < 0)
        {
            std::cerr << "Error: not a positive number => " << line << std::endl;
            continue;
        }
        if (result > 1000)
        {
            std::cerr << "Error: too large a number => " << line << std::endl;
            continue;
        }
        
        if (is_valid_price(value) == false)
        {
            std::cerr << "Error: Invalid input price format: => " << line << std::endl;
            continue;
        }

        for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); ++it)
        {
            if (date == it->first)
            {
                std::cout << date << " => " << result << " = " << result * it->second << std::endl; 
                break;
            }
            if (it != map.begin() && date < it->first)
            {
                std::cout << date << " => " << result << " = " << result * (--it)->second << std::endl; 
                break;
            }
            if (it == map.begin() && date < it->first)
            {
                std::cerr << "Error: input date before database date => " << line << std::endl;
                break;
            }
            if (it == --map.end())
            {
                std::cout << date << " => " << result << " = " << result * it->second << std::endl; 
                break;
            }
        }
        // for (size_t i = 0; i < date_vector.size(); ++i) 
        // {
        //     if (date == date_vector[i])
        //     {
        //         std::cout << date << " => " << result << " = " << result * price_vector[i] << std::endl; 
        //         break;
        //     }
        //     if (i > 0 && date < date_vector[i])
        //     {
        //         std::cout << date << " => " << result << " = " << result * price_vector[i - 1] << std::endl; 
        //         break;
        //     }
        //     if (i == 0 && date < date_vector[i])
        //     {
        //         std::cerr << "Error: input date before database date => " << line << std::endl;
        //         break;
        //     }
        //     if (i == date_vector.size() - 1)
        //     {
        //         std::cout << date << " => " << result << " = " << result * price_vector[i] << std::endl; 
        //         break;
        //     }
        // }
    }
}


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
    if (price.empty())
        return false;

    bool has_decimal_point = false;

    for (size_t i = 0; i < price.length(); ++i) 
    {
        if (price[i] == '.') 
        {
            if (has_decimal_point || i == price.length() - 1) // Check if there is more than one decimal point
                return false;
            has_decimal_point = true;
        } 
        else if (!std::isdigit(price[i])) // Check if the character is not a digit
            return false;
    }

    return true;
}