/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:16:22 by ateow             #+#    #+#             */
/*   Updated: 2024/02/15 18:28:47 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class   Zombie
{
    private:
        std::string name;
    public:
        Zombie(); // default constructor
        Zombie(std::string n); // param constructorls
        void announce( void );
        ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
