/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:35:50 by kali              #+#    #+#             */
/*   Updated: 2024/06/16 13:36:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <cstdlib>
#include <fstream>
#include <exception>
#include <algorithm>
#include <iostream>
# include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> map;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange& Org);
        BitcoinExchange& operator=(const BitcoinExchange& Org);
        ~BitcoinExchange();
        
        void compute(std::string filename);
        
};

bool is_valid_date(const std::string& date);
bool is_valid_price(const std::string& price);

#endif