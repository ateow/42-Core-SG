/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/04 00:57:11 by kali             ###   ########.fr       */
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
        dynamic_cast<A&>(p); 
        std::cout << "A class identified" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        dynamic_cast<B&>(p); 
        std::cout << "B class identified" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        dynamic_cast<C&>(p); 
        std::cout << "C class identified" << std::endl;
        return;
    }
    catch(...) {}
    std::cout << "Error, can't identify the class" << std::endl;
}

int main() 
{
    Base *b;
    b = generate();

    identify(b);
    identify(*b);

    delete b;
    return 0;
}