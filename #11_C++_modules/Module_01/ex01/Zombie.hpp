/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:16:22 by ateow             #+#    #+#             */
/*   Updated: 2024/02/06 22:28:24 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class   Zombie
{
    private:
        std::string name;
    public:
        Zombie() : name("Default") {}
        Zombie(std::string n) : name(n) {}  // constructor
        void announce( void );
};

Zombie* zombieHorde( int N, std::string name );