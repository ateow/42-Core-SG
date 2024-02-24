/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:32:47 by kali              #+#    #+#             */
/*   Updated: 2024/02/18 23:32:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   WrongAnimal
{
    protected:
        std::string type;

	public:
		//construct
		WrongAnimal();
		WrongAnimal(std::string type);

		//copy construct
		WrongAnimal(const WrongAnimal& original);
		
		// //copy operator assign
    	WrongAnimal& operator=(const WrongAnimal& original);
		
		//destructor
		~WrongAnimal();

		//member functions:
        std::string getType() const;
		void makeSound() const;
};



class   WrongCat : public WrongAnimal
{
	public:
		//construct
		WrongCat();

		//copy construct
		WrongCat(const WrongCat& original);
		
		// //copy operator assign
    	WrongCat& operator=(const WrongCat& original);
		
		//destructor
		~WrongCat();

		//member functions:
		void makeSound() const;
};