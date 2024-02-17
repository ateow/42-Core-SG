/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:09:27 by ateow             #+#    #+#             */
/*   Updated: 2024/02/17 18:15:10 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;

	public:
		//construct
		DiamondTrap();
		DiamondTrap(std::string name);

		//copy construct
		DiamondTrap(const DiamondTrap& original);
		
		// //copy operator assign
    	DiamondTrap& operator=(const DiamondTrap& original);
		
		//destructor
		~DiamondTrap();

		//member functions:
        void    attack(const std::string& target);
		// void    highFivesGuys();
        // void    guardGate();
        // void    takeDamage(unsigned int amount);
		// void    beRepaired(unsigned int amount);
        void    whoAmI();

};

#endif
