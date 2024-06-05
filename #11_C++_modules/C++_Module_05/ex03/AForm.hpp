/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:26:03 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 14:45:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _AFORM_HPP_
# define _AFORM_HPP_

# include <iostream>
# include <exception>
# include <sstream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign_status;
        const int required_sign_grade;
        const int required_exec_grade;
    
    public:    
        // constructor
        AForm();
        AForm(std::string name, int required_sign_grade, int required_exec_grade);

        // copy constructor
        AForm(AForm& Org);

        // copy operator assign
        AForm& operator=(AForm& Org);

        // destructor
        virtual ~AForm();
        
        // getters
        std::string get_name() const;
        int get_sign_status() const;
        int get_required_sign_grade() const;
        int get_required_exec_grade() const;

        void beSigned(Bureaucrat& Bur);
        void beExecuted(Bureaucrat const & Bur) const;
        virtual void exec() const = 0;
        virtual void setTarget(std::string tar) = 0;
        
        // classes
        class GradeTooHighException : public std::exception // inherit from public class exception
        {
            // public exception class have a what() method. use virtal to customise
            virtual const char *what() const throw();
        };
        
		class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& COUT, AForm& input);

#endif