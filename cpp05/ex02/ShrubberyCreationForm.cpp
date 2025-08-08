/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:55:56 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 15:11:03 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_LEVEL, SHRUBBERY_EXECUTE_LEVEL), _target("Default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_LEVEL, SHRUBBERY_EXECUTE_LEVEL), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    std::cout << "with values " << SHRUBBERY_SIGN_LEVEL << " and " << SHRUBBERY_EXECUTE_LEVEL << " and target " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_LEVEL, SHRUBBERY_EXECUTE_LEVEL), _target(copy.getTarget())
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return *this;
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    return *this;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
    return this->_target;
}

void ShrubberyCreationForm::generateTree(void) const
{
	std::string		filename = this->_target + "_shrubbery.txt";
	std::ofstream	f(filename.c_str());

	if (!f || !f.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}
	
	f << "      ccee88oo" << std::endl;
	f << "  C8O8O8Q8PoOb o8oo" << std::endl;
	f << " dOB69QO8PdUOpugoO9bD" << std::endl;
	f << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	f << "    6OuU  /p u gcoUodpP" << std::endl;
	f << "      \\\\ //  /douUP" << std::endl;
	f << "        \\/////" << std::endl;
	f << "         |||/\\" << std::endl;
	f << "         |||\\/" << std::endl;
	f << "         |||||" << std::endl;
	f << "   .....//||||\\...." << std::endl;
				  
	
	f.close();
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw ShrubberyCreationForm::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "ShrubberyCreationForm already signed" << std::endl;
        return;
    }
    this->_isSigned = true;
    std::cout << "ShrubberyCreationForm signed by " << bureaucrat.getName() << std::endl;
    return ;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
    {
        std::cout << "ShrubberyCreationForm is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() > this->_gradeToExecute)
        throw ShrubberyCreationForm::GradeTooLowException();
    this->generateTree();
    return ;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
    os << form.getName() << " is signed: " << form.getIsSigned() << std::endl;
    return os;
}