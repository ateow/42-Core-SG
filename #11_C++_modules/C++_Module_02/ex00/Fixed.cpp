/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:53:34 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 02:55:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default contstructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy contstructor called" << std::endl;
	this->fixed_point_value = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &original)
{
    if (this != &original) 
	{
		std::cout << "Copy assignment operator called" << std::endl;
   		this->fixed_point_value = original.getRawBits();
	}
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}