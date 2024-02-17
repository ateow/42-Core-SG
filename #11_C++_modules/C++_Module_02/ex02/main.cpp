/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:14 by kali              #+#    #+#             */
/*   Updated: 2024/02/12 11:02:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    std::cout << "\n<< subject tests >>" << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;


    std::cout << "\n<< increment >>" << std::endl;

    Fixed t;

    std::cout << t << std::endl;
    std::cout << ++t << std::endl;
    std::cout << t << std::endl;
    std::cout << t++ << std::endl;
    std::cout << t << std::endl;
    std::cout << --t << std::endl;
    std::cout << t << std::endl;
    std::cout << t-- << std::endl;
    std::cout << t << std::endl;


    std::cout << "\n<< + - * / >>" << std::endl;

    Fixed const plus( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const minus( Fixed( 5.05f ) - Fixed( 2 ) );
    Fixed const times( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const divide( Fixed( 5.05f ) / Fixed( 2 ) );
    
    std::cout << plus << std::endl;
    std::cout << minus << std::endl;
    std::cout << times << std::endl;
    std::cout << divide << std::endl;


    std::cout << "\n<< min & max >>" << std::endl;

    Fixed x(1.1f);
    Fixed y(1.2f);
    std::cout << "min: " << Fixed::min(x, y) << std::endl;
    std::cout << "max: " << Fixed::max(x, y) << std::endl;

    Fixed q(10.5);
    Fixed e(20.5);
    if (q < e)
        std::cout << "q is more then e" << std::endl;
    if (q > e)
        std::cout << "not suppose to print" << std::endl;
    if (q == e)
        std::cout << "not suppose to print" << std::endl;
    if (q == q)
        std::cout << "q = q" << std::endl;
    if (q != e)
        std::cout << "q != e" << std::endl;
    return 0;
}