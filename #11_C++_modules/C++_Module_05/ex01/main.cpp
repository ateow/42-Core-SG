/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 18:15:13 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{  
    std::cout << "\n=== initi Form requirement too low exception ===\n";
    try
    {
        Form form1("form1", 200, 200);
        // exception is thrown during the constructing
        // still constructing, hence destructor will not be called as it
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }

    std::cout << "\n=== Form requirement too high exception ===\n";
    try
    {
        Form form2("form2", 50, 50);
        std::cout << form2 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }

    std::cout << "\n=== Form Signing Fail ===\n";
    try
    {
        Bureaucrat aaron("aaron", 100);
        Form applyleave("applyleave", 50, 50);
        aaron.signForm(applyleave);
        std::cout << "\n=== Form Signing Success ===\n";
        aaron.setGrade(20);
        aaron.signForm(applyleave);;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }
}

