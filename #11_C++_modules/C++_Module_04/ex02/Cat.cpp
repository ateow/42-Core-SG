/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/20 20:11:22 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat()
{
    this->type = "Cat";
	std::cout << "Default Constructor: Cat Class" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& original) : Animal()
{
  	std::cout << "Initialising copy " << original.type << std::endl;
	*this = original;
	*this->brain = *original.brain;
}

Cat& Cat::operator=(const Cat &original)
{
	if (this != &original) 
	{
        this->type = original.type;
		*this->brain = *original.brain;
	    std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Goodbye " << this->type << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}

Brain* Cat::getBrain()
{
	return this->brain;
}