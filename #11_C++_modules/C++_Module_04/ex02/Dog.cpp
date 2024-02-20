/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/20 20:11:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog()
{
    this->type = "Dog";
	std::cout << "Default Constructor: Dog Class" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& original) : Animal()
{
  	std::cout << "Initialising copy " << original.type << std::endl;
	*this = original;
	*this->brain = *original.brain;
}

Dog& Dog::operator=(const Dog &original)
{
	if (this != &original) 
	{
        this->type = original.type;
		*this->brain = *original.brain;
	    std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Goodbye " << this->type << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof..." << std::endl;
}

Brain* Dog::getBrain()
{
	return this->brain;
}