/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:16:22 by ateow             #+#    #+#             */
/*   Updated: 2024/02/07 10:13:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class   Zombie
{
    private:
        std::string name;
    public:
        Zombie() {} // default constructor
        Zombie(std::string n) // param constructor
        {
            name = n;
        }
        void announce( void );
};

Zombie* zombieHorde( int N, std::string name );