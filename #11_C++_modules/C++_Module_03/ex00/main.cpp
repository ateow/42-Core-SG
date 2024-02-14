/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:22:26 by kali              #+#    #+#             */
/*   Updated: 2024/02/14 11:13:41 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
	ClapTrap *c1 = new ClapTrap("Luffy");
	ClapTrap *c2 = new ClapTrap("Zoro");
	ClapTrap *c3 = new ClapTrap(*c1);

	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
}