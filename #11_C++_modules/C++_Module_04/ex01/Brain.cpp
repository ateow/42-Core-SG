/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:23:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:18:14 by ateow            ###   ########.fr       */
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
    int i = 0;
	if (this != &original) 
	{
        while (i < 100)
        {
            this->ideas[i] = original.ideas[i];
            i++;
        }   
  	    std::cout << "Initialising = brain" << std::endl;
    }
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Class: Goodbye Brain" << std::endl;
}
