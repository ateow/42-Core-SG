/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:50:34 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 18:48:26 by kali             ###   ########.fr       */
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
        
        void exec();
        void setTarget(std::string tar);
};

#endif