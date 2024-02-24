/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:22:26 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 10:39:40 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
	// ClapTrap *c1 = new ClapTrap("Luffy");
	// ClapTrap *c2 = new ClapTrap("Zoro");
	// ClapTrap *c3 = new ClapTrap(*c1);

	// std::cout << std::endl;

	// c1->attack("Slime");
	// c2->attack("Sanji");
	// c3->attack("Slime shiny");

	// std::cout << std::endl;

	// c1->takeDamage(80);
	// c2->takeDamage(5);
	// c2->takeDamage(5);
	// c2->takeDamage(5);
	// c3->takeDamage(5);

	// std::cout << std::endl;

	// c1->beRepaired(1000);
	// c2->beRepaired(1);
	// c3->beRepaired(5);

	// std::cout << std::endl;

	// delete c1;
	// delete c2;
	// delete c3;

	// ScavTrap a1("hello");
	// ScavTrap a2(a1);

	// ScavTrap a3("world");
	// ScavTrap a4;
	// a4 = a3;

	ScavTrap s1("one");
	ScavTrap s2("two");
	ScavTrap s3("three");
	ScavTrap s4("four");
	std::cout << std::endl;
	s1.guardGate();
	s2.guardGate();
	s3.guardGate();
	s4.guardGate();
	std::cout << std::endl;
	s1.takeDamage(1000);
	s1.attack("target1");
	s1.beRepaired(1000);
	s2.attack("target2");
	s3.attack("target3");
	s4.attack("target4");
	s4.beRepaired(1000);
	std::cout << std::endl;
	ClapTrap c1("five");
	c1.takeDamage(2);
	c1.attack("target5");
	std::cout << std::endl;
}