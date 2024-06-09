/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/09 16:39:09 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    // typename T::iterator i = container.begin();
    // while (i < container.end())
    // {
    //     if (*i == value)
    //         return i;
    //     i++;
    // }
    // std::cerr << "Value: " << value << " not found in container" << std::endl;
    // return i;
    typename T::iterator it = std::find(container.begin(), container.end(), value);
	return it;
}

int main()
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; ++i) 
		v.push_back(i * i);
	std::cout << "Vector:" << std::endl;
	
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) 
		std::cout << *i << std::endl;

    it = easyfind(v, -3);
    if (it != v.end())
        std::cout << "Value: " << *it << " found in container" << std::endl;

    it = easyfind(v, 2);
    if (it != v.end())
        std::cout << "Value: " << *it << " found in container" << std::endl;

    it = easyfind(v, 25);
    if (it != v.end())
        std::cout << "Value: " << *it << " found in container" << std::endl;

    it = easyfind(v, 81);
    if (it != v.end())
        std::cout << "Value: " << *it << " found in container" << std::endl;

    return 0;

}