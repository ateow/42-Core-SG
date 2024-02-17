/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:49:34 by kali              #+#    #+#             */
/*   Updated: 2024/02/17 17:26:51 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class   FragTrap : public virtual ClapTrap
{
	public:
		//construct
		FragTrap();
		FragTrap(std::string name);

		//copy construct
		FragTrap(const FragTrap& original);
		
		// //copy operator assign
    	FragTrap& operator=(const FragTrap& original);
		
		//destructor
		~FragTrap();

		//member functions:
		void highFivesGuys();
};

#endif