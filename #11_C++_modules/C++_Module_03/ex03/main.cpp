/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:22:26 by kali              #+#    #+#             */
/*   Updated: 2024/02/17 18:09:24 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() 
{
	// DiamondTrap a1("hello");
	// DiamondTrap a2(a1);

	// DiamondTrap a3("world");
	// DiamondTrap a4;
	// a4 = a3;

	// DiamondTrap s0;
	DiamondTrap s1("BLINK");
	std::cout << std::endl;
	s1.attack("target1");
	s1.guardGate();
	s1.highFivesGuys();
	s1.beRepaired(1000);
	s1.whoAmI();
	std::cout << std::endl;

	
	// DiamondTrap s2("two");
	// DiamondTrap s3("three");
	// DiamondTrap s4("four");

	// s1.takeDamage(1000);
	// s1.beRepaired(1000);
	// s2.attack("target2");
	// s3.attack("target3");
	// s4.attack("target4");
	// s4.beRepaired(1000);
	
	// s1.highFivesGuys();
	// s2.highFivesGuys();
	// s3.highFivesGuys();
	// s4.highFivesGuys();
}