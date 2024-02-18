/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:49:34 by kali              #+#    #+#             */
/*   Updated: 2024/02/18 12:47:42 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class   ScavTrap : public ClapTrap
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