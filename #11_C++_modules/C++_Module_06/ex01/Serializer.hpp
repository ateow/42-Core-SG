/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:10 by kali              #+#    #+#             */
/*   Updated: 2024/06/04 00:00:33 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SERIALIZER_HPP_
# define _SERIALIZER_HPP_

# include <iostream>
# include <stdint.h>

struct Data 
{
	int nbr;
    std::string s; 
};

class Serializer
{
    private:
        // constructor
        Serializer();

        // copy constructor
        Serializer(Serializer& Org);

        // copy operator assign
        Serializer& operator=(Serializer& Org);
    
    public:

        // destructor
        ~Serializer();
       
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

bool isValidFloatLiteral(const std::string& str);
bool isValidDoubleLiteral(const std::string& str);
bool isValidIntLiteral(const std::string& str);

#endif