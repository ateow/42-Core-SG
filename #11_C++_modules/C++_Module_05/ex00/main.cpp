/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 17:58:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=== initi grade too low exception ===\n";
    try
    {
        Bureaucrat farmer("farmer", 200);
        farmer.demote_Grade(); 
        // exception is thrown during the constructing
        // still constructing, hence destructor will not be called as it
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }

    std::cout << "\n=== grade too low exception ===\n";
    try
    {
        Bureaucrat farmer("farmer", 150);
        farmer.demote_Grade(); // when an exception happens, destructor is called immediately
        Bureaucrat scholar("scholar", 1); // this will not run because an exception is thrown
        scholar.promote_Grade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }

    std::cout << "\n=== grade too high exception ===\n";
    try
    {
        Bureaucrat scholar("scholar", 1); 
        scholar.promote_Grade(); // this will not run because an exception is thrown
        Bureaucrat farmer("farmer", 150);// when an exception happens, destructor is called immediately
        farmer.demote_Grade(); 
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }

    std::cout << "\n=== initi and cout bureaucrat class ===\n";
    Bureaucrat* aaron = new Bureaucrat("aaron", 9);
    // Bureaucrat aaron("aaron", 9); // grade 9
    std::cout << *aaron << std::endl;
    aaron->promote_Grade(); // grade 8
    std::cout << *aaron << std::endl;
    aaron->demote_Grade(); // grade 9
    std::cout << *aaron << std::endl;
    delete aaron;

    std::cout << "\n=== initi copy constructor and assigment ===\n";
    Bureaucrat orginal("orginal", 88);
    Bureaucrat copy(orginal); // copy grade is 88
    std::cout << copy <<std::endl; 
    Bureaucrat orginal2("orginal2", 5);
    copy = orginal2; // copy grade is now 5. name remain same because its' constant
    std::cout << copy <<std::endl;
}
