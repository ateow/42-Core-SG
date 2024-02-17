/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:23:49 by ateow             #+#    #+#             */
/*   Updated: 2024/02/17 18:15:01 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    ClapTrap::name = "default_clap_name";
    this->name = "default";
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Initialising DiamondTrap Default: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    // ClapTrap::name = name.append("_clap_name");
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Initialising DiamondTrap " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& original) :
    ClapTrap(original.name), ScavTrap(original.name), FragTrap(original.name)
{
    this->name = original.name;
	this->hit_point = original.hit_point;
	this->energy_point = original.energy_point;
	this->attack_damage = original.attack_damage;
	std::cout << "DiamondTrap Copy Constructor " << this->name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &original)
{
    if (this != &original) 
	{
        this->name = original.name;
		this->hit_point = original.hit_point;
		this->energy_point = original.energy_point;
		this->attack_damage = original.attack_damage;
		std::cout << "DiamondTrap Copy Assignment " << this->name << std::endl;
	}
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Goodbye DiamondTrap " << this->name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

// void	DiamondTrap::highFivesGuys(void)
// {
//     this->FragTrap::highFivesGuys();
// 	std::cout << this->name << " high fives guys!" << std::endl;
// }

// void	DiamondTrap::guardGate(void)
// {
//     this->ScavTrap::guardGate();
// 	std::cout << "DiamondTrap " << this->name << " is in Gate Keeper mode." << std::endl;
// }

void    DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name << ", my ClapTrap name is " << ClapTrap::name << std::endl;
}
