/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/18 23:10:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog()
{
    this->type = "Dog";
	std::cout << "Default Constructor: Dog Class" << std::endl;
}

Dog::Dog(const Dog& original) : Animal()
{
  	std::cout << "Initialising copy " << original.type << std::endl;
	*this = original;
}

Dog& Dog::operator=(const Dog &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Dog::~Dog()
{
	std::cout << "Goodbye " << this->type << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof..." << std::endl;
}