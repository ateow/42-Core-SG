/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:16:22 by kali              #+#    #+#             */
/*   Updated: 2024/02/04 10:35:36 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

class Contact
{
public:
	string first_name;
	string last_name;
	string nickname;
	string phone_number;
	string darkest_secret;
};

class	PhoneBook
{
private:
	Contact mycontact[8];

public:
	void add_first_name(string input, int i) {mycontact[i].first_name = input;}
	void add_last_name(string input, int i) {mycontact[i].last_name = input;}
	void add_nickname(string input, int i) {mycontact[i].nickname = input;}
	void add_phone_number(string input, int i) {mycontact[i].phone_number = input;}
	void add_darkest_secret(string input, int i) {mycontact[i].darkest_secret = input;}
	void display_menu(int add_counter, int phonebook_size)
	{
		int i;
		string truncated;

		i = 0;
		while (i < add_counter && i < phonebook_size)
		{
			cout << "\n|";
			cout << std::setw(10) << std::right << i << "|";
			if (mycontact[i].first_name.length() >= 10)
			{
				truncated = mycontact[i].first_name.substr(0, 9);
				truncated = truncated.append(".");
			}
			else
				truncated = mycontact[i].first_name;
			cout << std::setw(10) << std::right << truncated << "|";
			if (mycontact[i].last_name.length() >= 10)
			{
				truncated = mycontact[i].last_name.substr(0, 9);
				truncated = truncated.append(".");
			}
			else
				truncated = mycontact[i].last_name;
			cout << std::setw(10) << std::right << truncated << "|";
			if (mycontact[i].nickname.length() >= 10)
			{
				truncated = mycontact[i].nickname.substr(0, 9);
				truncated = truncated.append(".");
			}
			else
				truncated = mycontact[i].nickname;
			cout << std::setw(10) << std::right << truncated;
			i++;
		}
		cout << "\n" << endl;
	}
	void display_contact(int i)
	{
		cout << "\nFirst Name: " << mycontact[i].first_name << endl;
		cout << "Last Name: " << mycontact[i].last_name << endl;
		cout << "Nickname: " << mycontact[i].nickname << endl;
		cout << "Phone Number: " << mycontact[i].phone_number << endl;
		cout << "Darkest Secret: " << mycontact[i].darkest_secret << "\n" << endl;
	}
};
