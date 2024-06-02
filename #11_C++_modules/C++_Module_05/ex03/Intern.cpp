/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:26:00 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 16:52:23 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

// constructor
Intern::Intern() 
{
    this->forms[0] = new ShrubberyCreationForm();
    this->forms[1] = new RobotomyRequestForm();
    this->forms[2] = new PresidentialPardonForm();
}

// copy constructor
Intern::Intern(Intern& Org)
{
    (void) Org;
    this->forms[0] = new ShrubberyCreationForm();
    this->forms[1] = new RobotomyRequestForm();
    this->forms[2] = new PresidentialPardonForm();
}


// copy operator assign
Intern& Intern::operator=(Intern& Org)
{
    (void) Org;
    this->forms[0] = new ShrubberyCreationForm();
    this->forms[1] = new RobotomyRequestForm();
    this->forms[2] = new PresidentialPardonForm();
    return *this;
}

// destructor
Intern::~Intern()
{
    delete forms[0];
    delete forms[1];
    delete forms[2];
}

// methods
AForm* Intern::makeForm(std::string form_name, std::string form_target)
{
    std::string fm[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;
    while (i < 3)
    {
        if (form_name == fm[i])
        {
            std::cout << "Intern creates " + form_name << std::endl;
            this->forms[i]->setTarget(form_target);
            return (this->forms[i]);
        };
    }
    std::cerr << "Intern failed to create form. " + form_name + " not found." << std::endl; 
    return NULL;
}