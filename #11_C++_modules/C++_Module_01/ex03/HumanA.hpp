/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:14:30 by kali              #+#    #+#             */
/*   Updated: 2024/02/09 22:44:54 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class HumanA
{
	private:
		std::string name;
		std::string *weapon;

	public:
		HumanA(std::string name, Weapon& W);
		void attack();
};
