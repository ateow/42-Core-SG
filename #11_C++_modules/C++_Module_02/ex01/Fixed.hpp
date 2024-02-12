/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:59 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 04:29:04 by kali             ###   ########.fr       */
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
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

