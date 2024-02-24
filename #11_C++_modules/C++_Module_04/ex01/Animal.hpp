/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:31:04 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:20:29 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Brain
{
	public:
		Brain();

		//copy construct
		Brain(const Brain& original);
		
		// //copy operator assign
    	Brain& operator=(const Brain& original);
		
		//destructor
		~Brain();
		
		std::string ideas[100];
};

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
	private:
		Brain *brain;
		
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
		Brain *getBrain();
};



class   Dog : public Animal
{
	private:
		Brain *brain;
		
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
		Brain *getBrain();
};


