/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:22:26 by kali              #+#    #+#             */
/*   Updated: 2024/02/17 17:24:49 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
	FragTrap a1("hello");
	FragTrap a2(a1);

	FragTrap a3("world");
	FragTrap a4;
	a4 = a3;

	FragTrap s1("one");
	FragTrap s2("two");
	FragTrap s3("three");
	FragTrap s4("four");

	s1.takeDamage(1000);
	s1.attack("target1");
	s1.beRepaired(1000);
	s2.attack("target2");
	s3.attack("target3");
	s4.attack("target4");
	s4.beRepaired(1000);
	
	s1.highFivesGuys();
	s2.highFivesGuys();
	s3.highFivesGuys();
	s4.highFivesGuys();
}