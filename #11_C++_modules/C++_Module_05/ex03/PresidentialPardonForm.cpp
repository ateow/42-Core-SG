/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:55:54 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 16:41:34 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

// constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
    // std::cout << "default constructor called for PresidentialPardonForm\n";
    this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string TARGET): AForm("PresidentialPardonForm", 25, 5)
{
    // std::cout << "constructor called for PresidentialPardonForm " << this->name << std::endl;
    this->target = TARGET;
}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& Org): AForm("PresidentialPardonForm", 25, 5)
{
    // std::cout << "copy constructor called for PresidentialPardonForm " << this->name << std::endl;
    this->target = Org.target;
}

// copy operator assign
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& Org)
{
    // std::cout << "copy operator assign called for PresidentialPardonForm " << this->name << std::endl;
    if (this != &Org)
    {
        this->target = Org.target;
    }
    return *this;
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "destructor called for PresidentialPardonForm " << this->name << std::endl;
}

void PresidentialPardonForm::exec() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::setTarget(std::string tar)
{
    this->target = tar;
}
