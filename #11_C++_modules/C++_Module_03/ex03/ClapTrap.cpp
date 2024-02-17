/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:19:02 by kali              #+#    #+#             */
/*   Updated: 2024/02/17 17:48:38 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
    name("default_clap_name"), 
    hit_point(10), 
    energy_point(10), 
    attack_damage(0)
{
	std::cout << "Initialising ClapTrap Default: " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
    name(name), 
    hit_point(10), 
    energy_point(10), 
    attack_damage(0)
{
	std::cout << "Initialising ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
  	std::cout << "Initialising copy " << original.name << std::endl;
	*this = original;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	if (this != &original) 
	{
        this->name = original.name;
		this->hit_point = original.hit_point;
		this->energy_point = original.energy_point;
		this->attack_damage = original.attack_damage;
	    std::cout << this->name << " = " << original.name << std::endl;
    }
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Goodbye ClapTrap " << this->name << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hit_point == 0)
    {
        std::cout << "Unable to attack. " << this->name << " is dead..." << std::endl;
        return ;
    }
    if (this->energy_point == 0)
    {
        std::cout << "Unable to attack. " << this->name << " has no energy points..." << std::endl;
        return ;
    }
	this->energy_point -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_point == 0)
    {
        std::cout << "Unable to take more damage. " << this->name << " is dead..." << std::endl;
        return ;
    }
    if (this->hit_point > amount)
	    this->hit_point -= amount;
    else
        this->hit_point = 0;
    std::cout << this->name << " took " <<  amount <<" damage" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_point == 0)
    {
        std::cout << "Unable to repair. " << this->name << " is dead..." << std::endl;
        return ;
    }
    if (this->energy_point == 0)
    {
        std::cout << "Unable to repair. " << this->name << " has no energy points..." << std::endl;
        return ;
    }
    this->hit_point += amount;
	this->energy_point -= 1;
    std::cout << this->name << " repaired " <<  amount << std::endl;
}
