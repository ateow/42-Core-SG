/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:31:14 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 12:58:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class   Point
{
	private:
        const Fixed x;
        const Fixed y;

	public:
		//construct
		Point();
        Point(const float a, const float b);
        Point(const Fixed a, const Fixed b);
		//copy construct
		Point(const Point& original);
		
		//copy operator assign
    	Point& operator=(const Point& original);
		
		//destructor
		~Point();

        //member functions:
        Fixed getX() const;
        Fixed getY() const;
};
