/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:50:09 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 10:55:06 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class   ClapTrap
{
	protected:
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
		virtual void    attack(const std::string& target);
		void    takeDamage(unsigned int amount);
		void    beRepaired(unsigned int amount);
};

#endif