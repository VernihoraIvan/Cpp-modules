/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:55:51 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 14:55:50 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", ROBOTOMY_SIGN_LEVEL, ROBOTOMY_EXECUTE_LEVEL), _target("Default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", ROBOTOMY_SIGN_LEVEL, ROBOTOMY_EXECUTE_LEVEL), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    std::cout << "with values " << ROBOTOMY_SIGN_LEVEL << " and " << ROBOTOMY_EXECUTE_LEVEL << " and target " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", ROBOTOMY_SIGN_LEVEL, ROBOTOMY_EXECUTE_LEVEL), _target(copy.getTarget())
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this == &copy)
        return *this;
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    return *this;
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
    return this->_target;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw RobotomyRequestForm::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "RobotomyRequestForm already signed" << std::endl;
        return;
    }
    this->_isSigned = true;
    std::cout << "RobotomyRequestForm signed by " << bureaucrat.getName() << std::endl;
    return ;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
    {
        std::cout << "RobotomyRequestForm is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() > this->_gradeToExecute)
        throw RobotomyRequestForm::GradeTooLowException();
    std::srand(std::time(0));
    if (std::rand() % 2)
    {
        std::cout << "RobotomyRequestForm robotomized by " << executor.getName() << std::endl;
        return ;
    }
    std::cout << "RobotomyRequestForm failed to robotomize " << this->_target << std::endl;
    return ;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
    os << form.getName() << " is signed: " << form.getIsSigned() << std::endl;
    return os;
}