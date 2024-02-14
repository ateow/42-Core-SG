/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:50:09 by kali              #+#    #+#             */
/*   Updated: 2024/02/14 11:55:24 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   ClapTrap
{
	private:
		std::string     name;
		unsigned int    hit_point;
		unsigned int    energy_point;
		unsigned int    attack_damage;

	public:
		//construct
		ClapTrap();
		ClapTrap(std::string name);

		//copy construct
		ClapTrap(const ClapTrap& original);
		
		//copy operator assign
		ClapTrap& operator=(const ClapTrap& original);
		
		//destructor
		~ClapTrap();

		//member function
		void    attack(const std::string& target);
		void    takeDamage(unsigned int amount);
		void    beRepaired(unsigned int amount);
};
