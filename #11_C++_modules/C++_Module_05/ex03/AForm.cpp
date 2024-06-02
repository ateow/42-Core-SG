/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:26:00 by kali              #+#    #+#             */
/*   Updated: 2024/06/02 16:52:23 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

// constructor
AForm::AForm(): name("Default")
{
    // std::cout << "default constructor called\n";
    this->sign_status = false;
}

AForm::AForm(std::string NAME, int REQ_SIGN_GRADE, int REQ_EXEC_GRADE): name(NAME)
{
    // std::cout << "constructor called for AForm " << this->name << std::endl;
    this->set_required_sign_grade(REQ_SIGN_GRADE);
    this->set_required_exec_grade(REQ_EXEC_GRADE);
    this->sign_status = false;
}

// copy constructor
AForm::AForm(AForm& Org): name(Org.name + "_copy")
{
    // std::cout << "copy constructor called for AForm " << this->name << std::endl;
    this->set_required_sign_grade(Org.required_sign_grade);
    this->set_required_exec_grade(Org.required_exec_grade);
    this->sign_status = Org.sign_status;
}

// copy operator assign
AForm& AForm::operator=(AForm& Org)
{
    // std::cout << "copy operator assign called for AForm " << this->name << std::endl;
    if (this != &Org)
    {
        this->set_required_sign_grade(Org.required_sign_grade);
        this->set_required_exec_grade(Org.required_exec_grade);
        this->sign_status = Org.sign_status;
    }
    return *this;
}

// destructor
AForm::~AForm()
{
    // std::cout << "destructor called for AForm " << this->name << std::endl;
}

// methods
void AForm::set_required_sign_grade(int REQ_SIGN_GRADE)
{
    // std::cout << "setting sign grade for AForm " << this->name << std::endl;
    if (REQ_SIGN_GRADE > 150)
        throw GradeTooLowException();
    else if (REQ_SIGN_GRADE < 1)
        throw GradeTooHighException();
    this->required_sign_grade = REQ_SIGN_GRADE;
}

void AForm::set_required_exec_grade(int REQ_EXEC_GRADE)
{
    // std::cout << "setting exec grade for AForm " << this->name << std::endl;
    if (REQ_EXEC_GRADE > 150)
        throw GradeTooLowException();
    else if (REQ_EXEC_GRADE < 1)
        throw GradeTooHighException();
    this->required_exec_grade = REQ_EXEC_GRADE;
}

std::string AForm::get_name()
{
    return(this->name);
}

int AForm::get_sign_status()
{
    return(this->sign_status);
}

int AForm::get_required_sign_grade()
{
    return(this->required_sign_grade);
}

int AForm::get_required_exec_grade()
{
    return(this->required_exec_grade);
}

void AForm::beSigned(Bureaucrat &Bur)
{
    std::cout << this->name + " form is being sign by " + Bur.getName() << std::endl;
    if (Bur.getGrade() > this->required_sign_grade)
        throw GradeTooLowException();
    else
        this->sign_status = true;        
}

void AForm::beExecuted(Bureaucrat &Bur)
{
    std::cout << this->name + " form is being executed by " + Bur.getName() << std::endl;
    if (this->sign_status == false)
    {
        std::cout << "couldn't execute form because it's not signed" << std::endl;
        return ;
    }
    if (Bur.getGrade() > this->required_exec_grade)
        throw GradeTooLowException();
    std::cout << Bur.getName() << " executed " << this->get_name() << std::endl;
    this->exec();
}


// overload <<
std::ostream& operator<<(std::ostream& COUT, AForm& input)
{
    std::ostringstream ss1;
    ss1 << input.get_required_sign_grade();

    std::ostringstream ss2;
    ss2 << input.get_required_exec_grade();

    std::ostringstream ss3;
    ss3 << input.get_sign_status();

    COUT << "AForm " + input.get_name() + " | " +
        "Sign Status " + ss3.str() + " | " +
        "Required Sign Grade " + ss1.str() + " | " +
        "Required Exec Grade " + ss2.str() + ".";
    return COUT;
}

// exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
    return("Required grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("Required grade too low.");
}