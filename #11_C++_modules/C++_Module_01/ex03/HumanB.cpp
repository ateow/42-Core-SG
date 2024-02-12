/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:43:24 by kali              #+#    #+#             */
/*   Updated: 2024/02/09 22:44:47 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->has_weapon = 0;
    weapon = new std::string("bare fists");
}

HumanB::~HumanB()
{
    if (has_weapon == 0)
        delete weapon;
}

void HumanB::setWeapon(Weapon& W)
{
    delete weapon;
    has_weapon = 1;
    weapon = &W.getType();
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << *weapon << std::endl;
}