/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:28:15 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 10:55:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*********** CONSTRUCTOR & DESTRUCTOR ***********/

Fixed::Fixed(void)
{
	// std::cout << "Default contstructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
	// shift bits by 8
	// shit 1 by 8: 10000000 means 256
	// std::cout << "Int contstructor called" << std::endl;
	this->fixed_point_value = value << this->frac_bits;
}

Fixed::Fixed(const float value)
{
	// multply float value by 256
	// std::cout << "Float contstructor called" << std::endl;
	this->fixed_point_value = roundf(value *(1 << this->frac_bits));
}

// copy constructor
Fixed::Fixed(const Fixed& original)
{
	// std::cout << "Copy contstructor called" << std::endl;
	this->fixed_point_value = original.getRawBits();
}

// copy assignment
Fixed& Fixed::operator=(const Fixed &original)
{
    if (this != &original) 
	{
		// std::cout << "Copy assignment operator called" << std::endl;
   		this->fixed_point_value = original.getRawBits();
	}
    return *this;
}

// destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/*********** Member functions ***********/

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

/*********** Operator Overload ***********/

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	if (this->fixed_point_value < fixed.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	if (this->fixed_point_value > fixed.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	if (this->fixed_point_value <= fixed.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	if (this->fixed_point_value >= fixed.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	if (this->fixed_point_value == fixed.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	if (this->fixed_point_value != fixed.fixed_point_value)
		return (true);
	return (false);
}

/*********** Arithmetic ***********/

Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed	res;
	
	res.fixed_point_value = this->fixed_point_value + fixed.fixed_point_value;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed	res;

	res.fixed_point_value = this->fixed_point_value - fixed.fixed_point_value;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed res(this->toFloat() * fixed.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed res(this->toFloat() / fixed.toFloat());
	return (res);
}

/*********** Incre / Decre ***********/

Fixed&	Fixed::operator++() // prefix ++a
{
	(this->fixed_point_value)++;
	return(*this);
}

Fixed	Fixed::operator++(int) // postfix a++, int is a dummy that compliler recongised
{
	Fixed tmp(*this);
	(this->fixed_point_value)++;
	return (tmp);
}

Fixed&	Fixed::operator--() // prefix ++a
{
	(this->fixed_point_value)--;
	return(*this);
}

Fixed	Fixed::operator--(int) // postfix a++, int is a dummy that compliler recongised
{
	Fixed tmp(*this);
	(this->fixed_point_value)--;
	return (tmp);
}

/*********** min / max ***********/

Fixed&	Fixed::min(Fixed& A, Fixed& B)
{
	if (A.fixed_point_value > B.fixed_point_value)
		return (B);
	return (A);
}

const Fixed&	Fixed::min(const Fixed& A, const Fixed& B)
{
	if (A.fixed_point_value > B.fixed_point_value)
		return (B);
	return (A);
}

Fixed&	Fixed::max(Fixed& A, Fixed& B)
{
	if (A.fixed_point_value > B.fixed_point_value)
		return (A);
	return (B);
}

const Fixed&	Fixed::max(const Fixed& A, const Fixed& B)
{
	if (A.fixed_point_value > B.fixed_point_value)
		return (A);
	return (B);
}