/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:21:12 by kali              #+#    #+#             */
/*   Updated: 2024/02/04 14:37:18 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	is_empty(string input)
{
	int i;
	i = 0;

	while (input[i] != '\0')
	{
     	if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n') 
            return 0;
		i++;
	}
	cout << "invalid inputs\n" << endl;
	return (1);
}

int	is_in_range(string s, int min, int max)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] - '0' >= min && s[i] - '0' <= max)
			i++;
		else
			return (0);
	}
	return (1);
}

int main(void)
{
	PhoneBook	myphonebook;
	string		input;
	int			i;
	int			add_counter;
	int			phonebook_size;

	phonebook_size = 8;
	add_counter = 0;
	i = 0;
	while (1)
	{
		cout << "Input Command (ADD, SEARCH, EXIT): ";
		getline(cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			cout << "Enter First Name: ";
			getline(cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_first_name(input, i);
			cout << "Enter Last Name: ";
			getline(cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_last_name(input, i);
			cout << "Enter Nickname: ";
			getline(cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_nickname(input, i);
			cout << "Enter Phone Number: ";
			getline(cin, input);
			if (is_empty(input) == 1) {continue;}
			myphonebook.add_phone_number(input, i);
			cout << "Enter Darkest Secret: ";
			getline(cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_darkest_secret(input, i);
			add_counter++;
			if (i == phonebook_size - 1)
				i = 0;
			else
				i++;
		}
		else if (input == "SEARCH")
		{
			if (add_counter > 0)
			{
				myphonebook.display_menu(add_counter, phonebook_size);
				cout << "Enter Index of Interest: ";
				getline(cin, input);
				if (is_empty(input) == 1) {continue;}
				if (is_in_range(input, 0, phonebook_size - 1) == 0 || (stoi(input) >= add_counter))
						cout << "invalid search index\n" << endl;
				else
					myphonebook.display_contact(stoi(input));
			}
			else
				cout << "no contacts added\n" << endl;
		}
		else
			cout << "invalid command\n" << endl;
	}
}
