/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:10 by kali              #+#    #+#             */
/*   Updated: 2024/06/01 22:49:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include <iostream>
# include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:    
        // constructor
        Bureaucrat();
        Bureaucrat(std::string NAME, int GRADE);

        // copy constructor
        Bureaucrat(Bureaucrat& Org);

        // copy operator assign
        Bureaucrat& operator=(Bureaucrat& Org);

        // destructor
        ~Bureaucrat();
       
        // methods
        std::string getName();
        int getGrade();
        void setGrade(int new_grade);
        void promote_Grade();
        void demote_Grade();

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

std::ostream& operator<<(std::ostream& COUT, Bureaucrat& input);

#endif