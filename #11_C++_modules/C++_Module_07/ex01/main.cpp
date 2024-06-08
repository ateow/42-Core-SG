/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 19:58:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// develop functions or Classes that are type generic

template <typename T> // template <typename T> create a new type call T. use T in the function
void iter(T* arr, int len, void (*func)(T &)) 
{
	int i;
	i = 0;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
}

template <typename T>
void toupper(T &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

template <typename T>
void add_one(T &arr)
{
	arr = arr + 1;
}

template <typename T>
void multiple_two(T &arr)
{
	arr = arr * 2;
}

int main( void ) 
{
	char arr[5] = {'a', 'b', 'c', 'd', 'e'};
	int len = sizeof(arr);
	
	for(int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	
	iter(arr, len, add_one);
	for(int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	iter(arr, len, toupper);
	for(int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n\n";


	int arr2[5] = {1, 2, 3, 4, 5};
	int len2 = 5;

	for(int i = 0; i < len2; i++)
		std::cout << arr2[i] << " ";
	std::cout << "\n";
	
	iter(arr2, len2, multiple_two);
	for(int i = 0; i < len2; i++)
		std::cout << arr2[i] << " ";
	std::cout << "\n";	

	iter(arr2, len2, toupper); // does not do anything because function type wrong
	for(int i = 0; i < len2; i++)
		std::cout << arr2[i] << " ";
	std::cout << "\n";	

	return 0;
}
