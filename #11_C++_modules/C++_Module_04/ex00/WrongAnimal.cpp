/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:45:57 by kali              #+#    #+#             */
/*   Updated: 2024/02/18 23:34:53 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "Default Constructor: WrongAnimal Class" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Initialising " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
  	std::cout << "Initialising copy " << original.type << std::endl;
	*this = original;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Goodbye " << this->type << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound..." << std::endl;
}