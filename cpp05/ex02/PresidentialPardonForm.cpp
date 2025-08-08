/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:55:46 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 14:42:28 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonFormDefaultName", PRESIDENTIAL_SIGN_LEVEL, PRESIDENTIAL_EXECUTE_LEVEL), _target("Default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", PRESIDENTIAL_SIGN_LEVEL, PRESIDENTIAL_EXECUTE_LEVEL), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    std::cout << "with values " << PRESIDENTIAL_SIGN_LEVEL << " and " << PRESIDENTIAL_EXECUTE_LEVEL << " and target " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", PRESIDENTIAL_SIGN_LEVEL, PRESIDENTIAL_EXECUTE_LEVEL), _target(copy.getTarget())
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this == &copy)
        return *this;
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    return *this;
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
    return this->_target;
}


void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw PresidentialPardonForm::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "PresidentialPardonForm already signed" << std::endl;
        return;
    }
    this->_isSigned = true;
    std::cout << "PresidentialPardonForm signed by " << bureaucrat.getName() << std::endl;
    return ;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
    {
        std::cout << "PresidentialPardonForm is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() > this->_gradeToExecute)
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return ;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
    os << form.getName() << " is signed: " << form.getIsSigned() << std::endl;
    return os;
}