/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:53:28 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 14:47:00 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    std::cout << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* meta = new Animal("abc animal");
    
    std::cout << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << meta->getType() << std::endl;
    
    std::cout << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << std::endl;
    delete i;
    delete j;
    delete meta;

    std::cout << std::endl;
    const WrongAnimal* k = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    delete k;
    

    // Animal hello;
    return 0;
}