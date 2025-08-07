/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:24:09 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/07 11:49:41 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form " << this->_name << " parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form " << this->_name << " copy constructor called" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form " << this->_name << " destructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Form " << this->_name << " assignment operator called" << std::endl;
    if (this == &copy)
        return *this;
    this->_isSigned = copy.getIsSigned();
    return *this;
}

const std::string &Form::getName(void) const
{
    return this->_name;
}

bool Form::getIsSigned(void) const
{
    return this->_isSigned;
}

int Form::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "Form " << this->_name << " is already signed" << std::endl;
        return;
    }
    this->_isSigned = true;
    std::cout << "Form " << this->_name << " signed by " << bureaucrat.getName() << std::endl;
    return;
}

void Form::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
    {
        std::cout << "Form " << this->_name << " is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() > this->_gradeToExecute)
        throw Form::GradeTooLowException();
    std::cout << "Form " << this->_name << " executed by " << executor.getName() << std::endl;
    return;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName() << " is signed: " << form.getIsSigned() << " Grade to sign: " << form.getGradeToSign() << " Grade to execute: " << form.getGradeToExecute();
    return os;
}
