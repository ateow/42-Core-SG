/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 18:17:42 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{  
    try
    {
        Bureaucrat aaron("aaron", 138);
        ShrubberyCreationForm S1("zzz");
        RobotomyRequestForm R1("zzz");
        PresidentialPardonForm P1("zzz");

        std::cout << "\n=== ShrubberyCreationForm Failure to execute, not signed ===\n";
        aaron.execForm(S1);

        std::cout << "\n=== ShrubberyCreationForm Failure to execute, invalid grade ===\n";
        aaron.signForm(S1);
        aaron.execForm(S1);

        std::cout << "\n=== ShrubberyCreationForm Success ===\n";
        aaron.promote_Grade();
        aaron.signForm(S1);
        aaron.execForm(S1);

        std::cout << "\n=== RobotomyRequestForm Failure to sign, invalid grade ===\n";
        aaron.signForm(R1);
        aaron.execForm(R1);

        std::cout << "\n=== RobotomyRequestForm Success ===\n";
        aaron.setGrade(40);
        aaron.signForm(R1);
        aaron.execForm(R1);

        std::cout << "\n=== PresidentialPardonForm Failure to sign, invalid grade ===\n";
        aaron.signForm(P1);
        aaron.execForm(P1);

        std::cout << "\n=== PresidentialPardonForm Success ===\n";
        aaron.setGrade(1);
        aaron.signForm(P1);
        aaron.execForm(P1);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }
}

