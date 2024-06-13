/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:59:25 by kali              #+#    #+#             */
/*   Updated: 2024/06/13 22:06:51 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input file>" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange x("data.csv");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    argc = argc;
    argv = argv;
}