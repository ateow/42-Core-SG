/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:21:12 by kali              #+#    #+#             */
/*   Updated: 2024/02/02 21:31:12 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	int c;
	char upper;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			c = 0;
			while(argv[i][c] != '\0')
			{
		upper = std::toupper(argv[i][c]);
				std::cout << upper;
				c++;
			}
			i++;
		}
		std::cout << std::endl;
	}
}
