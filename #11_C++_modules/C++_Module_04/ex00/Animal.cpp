/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:45:57 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 12:02:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Default Constructor: Animal Class" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Initialising " << type << std::endl;
}

Animal::Animal(const Animal& original)
{
  	std::cout << "Initialising copy " << original.type << std::endl;
	*this = original;
}

Animal& Animal::operator=(const Animal &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Class: Goodbye " << this->type << std::endl;
}

std::string Animal::getType() const
{
    return(this->type);
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound..." << std::endl;
}