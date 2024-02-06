/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:21:12 by kali              #+#    #+#             */
/*   Updated: 2024/02/05 20:26:57 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	is_empty(std::string input)
{
	int i;
	i = 0;

	while (input[i] != '\0')
	{
     	if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n') 
            return 0;
		i++;
	}
	std::cout << "invalid inputs\n" << std::endl;
	return (1);
}

int	is_in_range(std::string s, int min, int max)
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
	std::string		input;
	int			i;
	int			add_counter;
	int			phonebook_size;

	phonebook_size = 8;
	add_counter = 0;
	i = 0;
	while (1)
	{
		std::cout << "Input Command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			std::cout << "Enter First Name: ";
			std::getline(std::cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_first_name(input, i);
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_last_name(input, i);
			std::cout << "Enter Nickname: ";
			std::getline(std::cin, input);
			if (is_empty(input) == 1) {continue;}
  			myphonebook.add_nickname(input, i);
			std::cout << "Enter Phone Number: ";
			std::getline(std::cin, input);
			if (is_empty(input) == 1) {continue;}
			myphonebook.add_phone_number(input, i);
			std::cout << "Enter Darkest Secret: ";
			std::getline(std::cin, input);
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
				std::cout << "Enter Index of Interest: ";
				std::getline(std::cin, input);
				if (is_empty(input) == 1) {continue;}
				if (is_in_range(input, 0, phonebook_size - 1) == 0 || (std::atoi(input.c_str()) >= add_counter))
						std::cout << "invalid search index\n" << std::endl;
				else
					myphonebook.display_contact(std::atoi(input.c_str()));
			}
			else
				std::cout << "no contacts added\n" << std::endl;
		}
		else
			std::cout << "invalid command\n" << std::endl;
	}
}
