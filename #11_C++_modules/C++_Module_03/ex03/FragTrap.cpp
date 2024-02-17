/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:40:05 by ateow             #+#    #+#             */
/*   Updated: 2024/02/17 18:08:16 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "Initialising FragTrap Default: " << this->name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "Initialising FragTrap " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original.name)
{
	this->hit_point = original.hit_point;
	this->energy_point = original.energy_point;
	this->attack_damage = original.attack_damage;
	std::cout << "FragTrap Copy Constructor " << this->name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &original)
{
    if (this != &original) 
	{
        this->name = original.name;
		this->hit_point = original.hit_point;
		this->energy_point = original.energy_point;
		this->attack_damage = original.attack_damage;
		std::cout << "FragTrap Copy Assignment " << this->name << std::endl;
	}
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Goodbye FragTrap " << this->name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hit_point == 0) 
    {
		std::cout << "FragTrap " << this->name << " unable to high fives because is dead." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " high fives guys!" << std::endl;
}

