/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:59 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 02:54:09 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   Fixed
{
	private:
	
		int	fixed_point_value;
		static const int frac_bits = 8;

	public:
		//construct
		Fixed();

		//copy construct
		Fixed(const Fixed& orignal);
		
		//copy operator assign
    	Fixed& operator=(const Fixed& original);
		
		//destructor
		~Fixed();

		//member function:
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
};
