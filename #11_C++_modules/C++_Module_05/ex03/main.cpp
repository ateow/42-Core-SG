/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 18:19:12 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{  
    try
    {
        Bureaucrat aaron("aaron", 50);
        Intern somerandomintern;
        AForm * rrf;
        rrf = somerandomintern.makeForm("ShrubberyCreationForm", "zzz");
        aaron.signForm(*rrf);
        aaron.execForm(*rrf);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }
}