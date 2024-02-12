/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:11:12 by ateow             #+#    #+#             */
/*   Updated: 2024/02/06 21:50:35 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main(void)
{
    Zombie  *my_zombie = newZombie("Aaron");
    my_zombie->announce();
    delete my_zombie;

    randomChump("RandomZom1");
    randomChump("RandomZom2");
}

