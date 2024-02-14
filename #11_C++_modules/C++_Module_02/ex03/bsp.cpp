/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:58 by kali              #+#    #+#             */
/*   Updated: 2024/02/13 10:12:32 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed triangle_area(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed tmp = (p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY()));
    if (tmp.toFloat() < 0)
        tmp = tmp * Fixed(-1);
    Fixed area = Fixed(0.5f) * tmp; 

    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    Fixed   Total_area(triangle_area(a, b, c));
    Fixed   Area_1(triangle_area(a, b, point));
    Fixed   Area_2(triangle_area(a, c, point));
    Fixed   Area_3(triangle_area(b, c, point));

    if (Area_1 == 0 || Area_2 == 0 || Area_3 == 0)
        return (false);
    if (Total_area != Area_1 + Area_2 + Area_3)
        return (false);
    return (true);
}