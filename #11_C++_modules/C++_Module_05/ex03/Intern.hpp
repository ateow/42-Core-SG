/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:26:03 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 14:45:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _INTERN_HPP_
# define _INTERN_HPP_

# include <iostream>
# include <exception>
# include <sstream>

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        AForm* forms[3];

    public:    
        // constructor
        Intern();

        // copy constructor
        Intern(Intern& Org);

        // copy operator assign
        Intern& operator=(Intern& Org);

        // destructor
        ~Intern();
        
        // method
        AForm* makeForm(std::string form_name, std::string form_target);
};

#endif