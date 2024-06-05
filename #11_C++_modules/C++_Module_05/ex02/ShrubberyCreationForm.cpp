/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:55:54 by kali              #+#    #+#             */
/*   Updated: 2024/06/05 17:02:37 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

// constructor
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    // std::cout << "default constructor called for ShrubberyCreationForm\n";
    this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string TARGET): AForm("ShrubberyCreationForm", 145, 137)
{
    // std::cout << "constructor called for ShrubberyCreationForm " << this->name << std::endl;
    this->target = TARGET;
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& Org): AForm("ShrubberyCreationForm", 145, 137)
{
    // std::cout << "copy constructor called for ShrubberyCreationForm " << this->name << std::endl;
    this->target = Org.target;
}

// copy operator assign
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& Org)
{
    // std::cout << "copy operator assign called for ShrubberyCreationForm " << this->name << std::endl;
    if (this != &Org)
    {
        this->target = Org.target;
    }
    return *this;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "destructor called for ShrubberyCreationForm " << this->name << std::endl;
}

void ShrubberyCreationForm::exec() const
{
    std::string s = this->target + "_shrubbery";
    std::ofstream File(s.c_str());

    if (File.is_open()) {
        File << 
            "               ,@@@@@@@,\n"
            "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            "       |o|        | |         | |\n"
            "       |.|        | |         | |\n"
            "    \\_/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_\n"
            << std::endl;

        File.close();
    } 
    else 
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

