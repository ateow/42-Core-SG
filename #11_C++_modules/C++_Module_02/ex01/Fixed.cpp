/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:28:15 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 04:28:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default contstructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
	// shift bits by 8
	// shit 1 by 8: 10000000 means 256
	std::cout << "Int contstructor called" << std::endl;
	this->fixed_point_value = value << this->frac_bits;
}

Fixed::Fixed(const float value)
{
	// multply float value by 256
	std::cout << "Float contstructor called" << std::endl;
	this->fixed_point_value = roundf(value *(1 << this->frac_bits));
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

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	// divide value back by 256 
	return (float)this->fixed_point_value / (1 << this->frac_bits);
}

int		Fixed::toInt(void) const
{
	// shift back to the right
	return(this->fixed_point_value >> this->frac_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}