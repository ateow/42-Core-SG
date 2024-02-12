/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:14:52 by kali              #+#    #+#             */
/*   Updated: 2024/02/09 22:44:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class HumanB
{
	private:
		std::string name;
		std::string *weapon;
		int	has_weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& W);
		void attack();
};