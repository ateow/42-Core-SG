/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:50:34 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 16:21:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ROBOTOMYREQUESTFORM_HPP_
# define _ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"
# include <iostream>
# include <exception>
 #include <string>
# include <cstdlib> // For srand, rand

class RobotomyRequestForm : public AForm
{
    private:
        const std::string name;
        std::string target;
    
    public:    
        // constructor
        RobotomyRequestForm();
        RobotomyRequestForm(std::string TARGET);

        // copy constructor
        RobotomyRequestForm(RobotomyRequestForm& Org);

        // copy operator assign
        RobotomyRequestForm& operator=(RobotomyRequestForm& Org);

        // destructor
        ~RobotomyRequestForm();
        
        void exec(); // must have this because AFORM is abstract and require this

};

#endif