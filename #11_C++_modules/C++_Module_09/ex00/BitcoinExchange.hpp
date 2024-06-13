/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:35:50 by kali              #+#    #+#             */
/*   Updated: 2024/06/13 22:14:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <exception>
#include <algorithm>
#include <iostream>

class BitcoinExchange
{
    private:
        std::vector<float> price_vector;
        std::vector<std::string> date_vector;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange& Org);
        BitcoinExchange& operator=(const BitcoinExchange& Org);
        ~BitcoinExchange();
        
        
};

#endif