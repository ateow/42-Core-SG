/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:40:01 by ateow            ###   ########.fr       */
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
    this->type = original.type;
	this->brain = new Brain(*original.brain);
}

Cat& Cat::operator=(const Cat &original)
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

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat class: Goodbye " << this->type << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}

Brain* Cat::getBrain()
{
	return this->brain;
}