/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:16:22 by kali              #+#    #+#             */
/*   Updated: 2024/02/05 20:58:03 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class	PhoneBook
{
private:
	Contact mycontact[8];

public:
	void add_first_name(std::string input, int i) {mycontact[i].first_name = input;}
	void add_last_name(std::string input, int i) {mycontact[i].last_name = input;}
	void add_nickname(std::string input, int i) {mycontact[i].nickname = input;}
	void add_phone_number(std::string input, int i) {mycontact[i].phone_number = input;}
	void add_darkest_secret(std::string input, int i) {mycontact[i].darkest_secret = input;}
	void display_menu(int add_counter, int phonebook_size)
	{
		int i;
		std::string truncated;

		i = 0;
		while (i < add_counter && i < phonebook_size)
		{
			std::cout << "\n|";
			std::cout << std::setw(10) << std::right << i << "|";
			if (mycontact[i].first_name.length() >= 10)
			{
				truncated = mycontact[i].first_name.substr(0, 9);
				truncated = truncated.append(".");
			}
			else
				truncated = mycontact[i].first_name;
			std::cout << std::setw(10) << std::right << truncated << "|";
			if (mycontact[i].last_name.length() >= 10)
			{
				truncated = mycontact[i].last_name.substr(0, 9);
				truncated = truncated.append(".");
			}
			else
				truncated = mycontact[i].last_name;
			std::cout << std::setw(10) << std::right << truncated << "|";
			if (mycontact[i].nickname.length() >= 10)
			{
				truncated = mycontact[i].nickname.substr(0, 9);
				truncated = truncated.append(".");
			}
			else
				truncated = mycontact[i].nickname;
			std::cout << std::setw(10) << std::right << truncated;
			i++;
		}
		std::cout << "\n" << std::endl;
	}
	void display_contact(int i)
	{
		std::cout << "\nFirst Name: " << mycontact[i].first_name << std::endl;
		std::cout << "Last Name: " << mycontact[i].last_name << std::endl;
		std::cout << "Nickname: " << mycontact[i].nickname << std::endl;
		std::cout << "Phone Number: " << mycontact[i].phone_number << std::endl;
		std::cout << "Darkest Secret: " << mycontact[i].darkest_secret << "\n" << std::endl;
	}
};
