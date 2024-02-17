/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:40:05 by ateow             #+#    #+#             */
/*   Updated: 2024/02/17 18:12:51 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "Initialising ScavTrap Default: " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "Initialising ScavTrap " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original.name)
{
	this->hit_point = original.hit_point;
	this->energy_point = original.energy_point;
	this->attack_damage = original.attack_damage;
	std::cout << "ScavTrap Copy Constructor " << this->name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
    if (this != &original) 
	{
        this->name = original.name;
		this->hit_point = original.hit_point;
		this->energy_point = original.energy_point;
		this->attack_damage = original.attack_damage;
		std::cout << "ScavTrap Copy Assignment " << this->name << std::endl;
	}
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Goodbye ScavTrap " << this->name << std::endl;
};

void    ScavTrap::attack(const std::string& target)
{
    if (this->hit_point == 0)
    {
        std::cout << "Unable to attack. " << "ScavTrap " << this->name << " is dead..." << std::endl;
        return ;
    }
    if (this->energy_point == 0)
    {
        std::cout << "Unable to attack. " << "ScavTrap " << this->name << " has no energy points..." << std::endl;
        return ;
    }
	this->energy_point -= 1;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is in Gate Keeper mode." << std::endl;
}

