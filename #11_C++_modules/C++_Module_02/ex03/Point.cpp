/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:17:57 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 12:59:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(0), y(0) {}
Point::Point(const float a, const float b): x(a), y(b) {}
Point::Point(const Fixed a, const Fixed b): x(Fixed(a)), y(Fixed(b)) {}
Point::Point(const Point& original) : x(original.x),y(original.y) {}
Point& Point::operator=(const Point &original)
{
    if (this != &original) 
	{
        const_cast<Fixed&>(x) = original.x;
        const_cast<Fixed&>(y) = original.y;
    }
    return *this;
}
Point::~Point(){};

Fixed Point::getX() const 
{
	return this->x;
}

Fixed Point::getY() const 
{
	return this->y;
}