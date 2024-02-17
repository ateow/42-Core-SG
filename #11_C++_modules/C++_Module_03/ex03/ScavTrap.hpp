/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:49:34 by kali              #+#    #+#             */
/*   Updated: 2024/02/17 15:40:15 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class   ScavTrap : public virtual ClapTrap
{
	public:
		//construct
		ScavTrap();
		ScavTrap(std::string name);

		//copy construct
		ScavTrap(const ScavTrap& original);
		
		// //copy operator assign
    	ScavTrap& operator=(const ScavTrap& original);
		
		//destructor
		~ScavTrap();

		//member functions:
		void guardGate();
		void attack(const std::string& target);
};

#endif