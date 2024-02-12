/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:31:14 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 12:18:24 by kali             ###   ########.fr       */
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
		//copy construct
		Point(const Point& orignal);
		
		//copy operator assign
    	Point& operator=(const Point& original);
		
		//destructor
		~Point();

};
