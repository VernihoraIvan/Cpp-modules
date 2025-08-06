/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:42:43 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/06 13:31:27 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default")
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "Bureaucrat " << this->_name << " parameterized constructor called" << std::endl;
    if (grade < 1)
    {
        std::cout << "Grade too high" << std::endl;
        throw GradeTooHighException();
    }
    if (grade > 150)
    {
        std::cout << "Grade too low" << std::endl;
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    this->_grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_grade = copy._grade;
    return (*this);
}

const std::string &Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();    
    this->_grade--;
    std::cout << "Incrementing grade" << std::endl;
    std::cout << "New grade: " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
    std::cout << "Decrementing grade" << std::endl;
    std::cout << "New grade: " << this->_grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}