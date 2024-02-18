/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/18 23:35:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
	std::cout << "Default Constructor: WrongCat Class" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal()
{
  	std::cout << "Initialising copy " << original.type << std::endl;
	*this = original;
}

WrongCat& WrongCat::operator=(const WrongCat &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Goodbye " << this->type << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}