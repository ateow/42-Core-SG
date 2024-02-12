/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:59 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 10:55:44 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

class   Fixed
{
	private:
	
		int	fixed_point_value;
		static const int frac_bits = 8;

	public:
		//construct
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);

		//copy construct
		Fixed(const Fixed& orignal);
		
		//copy operator assign
    	Fixed& operator=(const Fixed& original);
		
		//destructor
		~Fixed();

		//member function:
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//operator overload:
		bool	operator<(const Fixed& fixed) const;
		bool	operator>(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;

		Fixed	operator+(const Fixed& fixed);
		Fixed	operator-(const Fixed& fixed);
		Fixed	operator*(const Fixed& fixed);
		Fixed	operator/(const Fixed& fixed);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		//min max:
		static Fixed&	min(Fixed& A, Fixed& B);
		static const Fixed&	min(const Fixed& A, const Fixed& B);
		static Fixed&	max(Fixed& A, Fixed& B);
		static const Fixed&	max(const Fixed& A, const Fixed& B);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
