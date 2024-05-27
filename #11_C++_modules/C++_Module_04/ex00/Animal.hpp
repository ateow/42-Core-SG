/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:31:04 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 12:01:18 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   Animal
{
    protected:
        std::string type;

	public:
		//construct
		Animal();
		Animal(std::string type);

		//copy construct
		Animal(const Animal& original);
		
		// //copy operator assign
    	Animal& operator=(const Animal& original);
		
		//destructor
		virtual ~Animal();

		//member functions:
        std::string getType() const;
		virtual void makeSound() const;
};



class   Cat : public Animal
{
	public:
		//construct
		Cat();

		//copy construct
		Cat(const Cat& original);
		
		// //copy operator assign
    	Cat& operator=(const Cat& original);
		
		//destructor
		~Cat();

		//member functions:
		void makeSound() const;
};



class   Dog : public Animal
{
	public:
		//construct
		Dog();

		//copy construct
		Dog(const Dog& original);
		
		// //copy operator assign
    	Dog& operator=(const Dog& original);
		
		//destructor
		~Dog();

		//member functions:
		void makeSound() const;
};