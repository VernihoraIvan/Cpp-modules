/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:24:09 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/07 12:09:40 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form " << this->_name << " parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form " << this->_name << " copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "Form " << this->_name << " destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "Form " << this->_name << " assignment operator called" << std::endl;
    if (this == &copy)
        return *this;
    this->_isSigned = copy.getIsSigned();
    return *this;
}

const std::string &AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getIsSigned(void) const
{
    return this->_isSigned;
}

int AForm::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "Form " << this->_name << " is already signed" << std::endl;
        return;
    }
    this->_isSigned = true;
    std::cout << "Form " << this->_name << " signed by " << bureaucrat.getName() << std::endl;
    return;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
    {
        std::cout << "Form " << this->_name << " is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    std::cout << "Form " << this->_name << " executed by " << executor.getName() << std::endl;
    return;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form " << form.getName() << " is signed: " << form.getIsSigned() << " Grade to sign: " << form.getGradeToSign() << " Grade to execute: " << form.getGradeToExecute();
    return os;
}
