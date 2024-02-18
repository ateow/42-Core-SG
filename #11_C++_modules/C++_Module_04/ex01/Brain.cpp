/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:23:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/19 00:26:33 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Brain::Brain()
{
	std::cout << "Default Constructor: Brain Class" << std::endl;
}

Brain::Brain(const Brain& original)
{
  	std::cout << "Initialising copy brain" << std::endl;
	*this = original;
}

Brain& Brain::operator=(const Brain &original)
{
	if (this != &original) 
	{
        this->ideas = original.ideas;
	    // std::cout << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Brain::~Brain()
{
	std::cout << "Goodbye " << this->type << std::endl;
}
