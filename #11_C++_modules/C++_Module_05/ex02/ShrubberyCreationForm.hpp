/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:50:34 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 17:33:02 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define _SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"
# include <iostream>
# include <exception>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string name;
        std::string target;
    
    public:    
        // constructor
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string TARGET);

        // copy constructor
        ShrubberyCreationForm(ShrubberyCreationForm& Org);

        // copy operator assign
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& Org);

        // destructor
        ~ShrubberyCreationForm();
        
        void exec(); // must have this because AFORM is abstract and require this

};

#endif