/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:49:34 by kali              #+#    #+#             */
/*   Updated: 2024/02/14 12:05:38 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

class   ScavTrap : public ClapTrap
{
	private:


	public:
		//construct
		ScavTrap();
		ScavTrap(std::string name):ClapTrap(std::string name);

		//copy construct
		ScavTrap
	(const ScavTrap& orignal);
		
		//copy operator assign
    	ScavTrap& operator=(const ScavTrap& original);
		
		//destructor
		~ScavTrap();
};

ScavTrap::ScavTrap()
{
	this->name = "Default";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "Initialising ScavTrap " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
	name(name),
	hit_point(100),
	energy_point(50),
	attack_damage(20),
{
	std::cout << "Initialising ScavTrap " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& orignal)
{

}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
    if (this != &original) 
	{
        // Implement the copy assignment logic here
    }
    return *this;
}


ScavTrap::~ScavTrap(){};



/*
:
	name(name),
	hit_point(100),
	energy_point(50),
	attack_damage(20),
*/