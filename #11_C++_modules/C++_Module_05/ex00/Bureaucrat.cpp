/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:14 by kali              #+#    #+#             */
/*   Updated: 2024/06/01 23:17:11 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

// constructor
Bureaucrat::Bureaucrat()
{
    std::cout << "default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string NAME, int GRADE): name(NAME)
{
    std::cout << "constructor called for " << this->name << std::endl;
    setGrade(GRADE);
}

// copy constructor
Bureaucrat::Bureaucrat(Bureaucrat& Org): name(Org.name + "_copy")
{
    std::cout << "copy constructor called for " << this->name << std::endl;
    setGrade(Org.grade);
}

// copy operator assign
Bureaucrat& Bureaucrat::operator=(Bureaucrat& Org)
{
    std::cout << "copy operator assign called for " << this->name << std::endl;
    if (this != &Org)
        setGrade(Org.grade);
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called for " << this->name << std::endl;
}

// methods
std::string Bureaucrat::getName()
{
    return(this->name);
}

int Bureaucrat::getGrade()
{
    return(this->grade);
}

void Bureaucrat::setGrade(int new_grade)
{
    if (new_grade > 150)
        throw GradeTooLowException();
    else if (new_grade < 1)
        throw GradeTooHighException();
    this->grade = new_grade;
}


void Bureaucrat::promote_Grade()
{
    std::cout << "promote " << this->name << std::endl;
    setGrade(this->grade - 1);
}

void Bureaucrat::demote_Grade()
{
    std::cout << "demote " << this->name << std::endl;
    setGrade(this->grade + 1);
}

// overload <<
std::ostream& operator<<(std::ostream& COUT, Bureaucrat& input)
{
    COUT << input.getName() << ", bureaucat grade " << input.getGrade() << ".";
    return COUT;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat's grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat's grade too low.");
}