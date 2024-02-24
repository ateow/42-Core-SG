/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:35:32 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:54:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* cloud = new Character("cloud");

    std::cout << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    cloud->equip(tmp);
    tmp = src->createMateria("cure");
    cloud->equip(tmp);
    ICharacter* bob = new Character("bob");

    std::cout << std::endl;
    cloud->use(0, *bob);
    cloud->use(1, *bob);
    std::cout << std::endl;

    delete bob;
    delete cloud;
    delete src;
}