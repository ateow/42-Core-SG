/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:25:24 by kali              #+#    #+#             */
/*   Updated: 2024/02/09 22:43:19 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& W)
{
    this->name = name;
    weapon = &W.getType();
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << *weapon << std::endl;
}