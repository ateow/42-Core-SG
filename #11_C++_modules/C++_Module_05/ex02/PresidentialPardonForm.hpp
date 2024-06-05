/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:50:34 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 16:21:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PRESIDENTIALPARDONFORM_HPP_
# define _PRESIDENTIALPARDONFORM_HPP_

# include "AForm.hpp"
# include <iostream>
# include <exception>
 #include <string>

class PresidentialPardonForm : public AForm
{
    private:
        const std::string name;
        std::string target;
    
    public:    
        // constructor
        PresidentialPardonForm();
        PresidentialPardonForm(std::string TARGET);

        // copy constructor
        PresidentialPardonForm(PresidentialPardonForm& Org);

        // copy operator assign
        PresidentialPardonForm& operator=(PresidentialPardonForm& Org);

        // destructor
        ~PresidentialPardonForm();
        
        void exec() const; // must have this because AFORM is abstract and require this

};

#endif