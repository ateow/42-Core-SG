/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:12:12 by ateow             #+#    #+#             */
/*   Updated: 2024/02/06 22:29:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    Zombie* my_army = new Zombie[N];

    // Initialize each Zombie in the array with the given name
    while (i < N)
    {
        my_army[i] = Zombie(name);
        i++;
    }

    i = 0;
    while (i < N)
    {
        my_army[i].announce();
        i++;
    }
    // Return a pointer to the first element of the array
    return my_army;
}
