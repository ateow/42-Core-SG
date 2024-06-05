/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 00:25:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// develop functions or Classes that are type generic

template <typename T> // template <typename T> create a new type call T. use T in the function
void swap(T &a, T &b) 
{
	T tmp;
	tmp = b;
	b = a;
	a = tmp;
}

template <typename T> 
T& min(T &a, T &b)
{
	if (a == b)
		return b;
	else if (a < b)
		return a;
	else
		return b;
}

template <typename T> 
T& max(T &a, T &b)
{
	if (a == b)
		return b;
	else if (a < b)
		return b;
	else
		return a;
}

int main( void ) 
{
	int a = 2;
	int b = 3;
	
	::swap( a, b ); // ::swap to access a global variable when there is a local variable with same name: 
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
