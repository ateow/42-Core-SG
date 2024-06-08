/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 15:22:55 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base::~Base() {}

Base* generate()
{
	std::srand(time(NULL));

	int n = rand() % 3;
	switch (n) {
		case 0:
			std::cout << "A class generated" << std::endl;
			return new A;
		case 1:
			std::cout << "B class generated" << std::endl;
			return new B;
		case 2:
			std::cout << "C class generated" << std::endl;
			return new C;
	}
    std::cout << "error, return NULL" << std::endl;
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL) 
		std::cout << "A class identified" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL) 
		std::cout << "B class identified" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL) 
		std::cout << "C class identified" << std::endl;
	else 
		std::cout << "Error, can't identify the class" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void) dynamic_cast< A& >( p ); 
        std::cout << "A class identified" << std::endl;
        return;
    }
    catch(...) {} // Catch all other exceptions
    try
    {
        (void) dynamic_cast<B&>(p); 
        std::cout << "B class identified" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        (void) dynamic_cast<C&>(p); 
        std::cout << "C class identified" << std::endl;
        return;
    }
    catch(...) {}
    std::cout << "Error, can't identify the class" << std::endl;
}

// With Pointers:
// dynamic_cast returns nullptr on failure.
// You check for nullptr to determine if the cast was successful.
// Simple and straightforward error handling.
 
// With References:
// dynamic_cast throws a std::bad_cast exception on failure.
// You need to use try and catch blocks to handle these exceptions.
// Necessary because references cannot be null, and throwing an exception is the only way to indicate a failure.

int main() 
{
    Base *b;
    b = generate();

    identify(*b);
    identify(b);

    delete b;
    return 0;
}