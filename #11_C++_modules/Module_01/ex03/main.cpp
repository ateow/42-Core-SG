/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:43:48 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 12:34:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(){}
		Weapon(std::string type)
		{
			this->type = type;
		}
		std::string& getType() 
		{
			return((this->type));
		}

		void setType(std::string type)
		{
			this->type = type;
		}

};

class HumanA
{
	private:
		std::string name;
		std::string *weapon;

	public:
		HumanA(std::string name, Weapon& W)
		{
			this->name = name;
			weapon = &W.getType();
		}

		void attack()
		{
			std::cout << name << " attacks with their " << *weapon << std::endl;
		}
};


class HumanB
{
	private:
		std::string name;
		std::string *weapon;
		int	has_weapon;

	public:
		HumanB(std::string name)
		{
			this->name = name;
			this->has_weapon = 0;
			weapon = new std::string("bare fists");
		}

		~HumanB()
		{
			if (has_weapon == 0)
				delete weapon;
		}
		
		void setWeapon(Weapon& W)
		{
			delete weapon;
			has_weapon = 1;
			weapon = &W.getType();
		}

		void attack()
		{
			std::cout << name << " attacks with their " << *weapon << std::endl;
		}
};



int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}