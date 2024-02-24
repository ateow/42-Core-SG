/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:41:23 by ateow            ###   ########.fr       */
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
    this->type = original.type;
	this->brain = new Brain(*original.brain);
}

Dog& Dog::operator=(const Dog &original)
{
	if (this != &original) 
	{
        this->type = original.type;
		if (this->brain != NULL)
		{
			delete this->brain;
			this->brain = new Brain(*original.brain);
		}
		else
			this->brain = new Brain(*original.brain);
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