/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 19:57:08 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <stdlib.h>

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
const T& min(const T& a, const T& b) 
{
	if (a == b)
		return b;
	else if (a < b)
		return a;
	else
		return b;
}

template <typename T> 
const T& max(const T& a, const T& b) 
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

    int* e = new int[2];
    int* f = new int[2];

	f[0] = 3;
	f[1] = 4;
	e[0] = 1;
	e[1] = 2;
	
	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	delete[] e;
	delete[] f;
	return 0;
	
}
