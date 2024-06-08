/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 19:22:44 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "Array.hpp"

// int main()
// {
// 	try
// 	{
// 		std::cout << "\n===== INT array no parameter =====" << std::endl;
// 		Array<int> x;
// 		std::cout << "size: " << x.size() << std::endl;
// 		std::cout << "value of x[10]: " << x[10] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		std::cout << "\n===== INT array size 20 =====" << std::endl;
// 		Array<int> x(20);
// 		std::cout << "size: " << x.size() << std::endl;
// 		std::cout << "value of x[19]: " << x[19] << std::endl;
// 		std::cout << "value of x[20]: " << x[20] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		std::cout << "\n===== CHAR array size 20 =====" << std::endl;
// 		Array<char> x(20);
// 		std::cout << "size: " << x.size() << std::endl;
// 		std::cout << "value of x[19]: " << x[19] << std::endl;
// 		std::cout << "value of x[20]: " << x[20] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return 0;
// }

# include <iostream>
# include <cstdlib>
# include "Array.hpp"
# define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
		if (i < 5)
			std::cout << mirror[i] << " | " << numbers[i] << std::endl;

        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	
    try
    {
        numbers[MAX_VAL] = 0; //max_val not valid, index out of range. 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		if (i < 10)
			std::cout << numbers[i] << std::endl;
    }
	
    delete [] mirror;
	return 0;
}