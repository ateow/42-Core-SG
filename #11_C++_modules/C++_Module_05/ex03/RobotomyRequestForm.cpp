/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:55:54 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 17:56:40 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

// constructor
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    // std::cout << "default constructor called for RobotomyRequestForm\n";
    this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string TARGET): AForm("RobotomyRequestForm", 72, 45)
{
    // std::cout << "constructor called for RobotomyRequestForm " << this->name << std::endl;
    this->target = TARGET;
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& Org): AForm("RobotomyRequestForm", 72, 45)
{
    // std::cout << "copy constructor called for RobotomyRequestForm " << this->name << std::endl;
    this->target = Org.target;
}

// copy operator assign
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& Org)
{
    // std::cout << "copy operator assign called for RobotomyRequestForm " << this->name << std::endl;
    if (this != &Org)
    {
        this->target = Org.target;
    }
    return *this;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "destructor called for RobotomyRequestForm " << this->name << std::endl;
}

void RobotomyRequestForm::exec() const
{
    srand((long) this); // srand seeds the random number generator used by rand(). Using the this pointer as a seed can help in generating different random sequences for different instances of a class.
    if (rand() & 1) 
	{
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    }
    else 
	{
        std::cout << this->target << " robotomy failed." << std::endl;
    }
}

void RobotomyRequestForm::setTarget(std::string tar)
{
    this->target = tar;
}
