/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:26:03 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 18:10:16 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _FORM_HPP_
# define _FORM_HPP_

# include <iostream>
# include <exception>
# include <sstream>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign_status;
        const int required_sign_grade;
        const int required_exec_grade;
    
    public:    
        // constructor
        Form();
        Form(std::string name, int required_sign_grade, int required_exec_grade);

        // copy constructor
        Form(Form& Org);

        // copy operator assign
        Form& operator=(Form& Org);

        // destructor
        ~Form();
        
        // getters
        std::string get_name();
        int get_sign_status();
        int get_required_sign_grade();
        int get_required_exec_grade();

        void beSigned(Bureaucrat &Bur);
        
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

std::ostream& operator<<(std::ostream& COUT, Form& input);

#endif