/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:15:15 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/18 14:18:35 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{   
    std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this == &other)
    return *this;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            switch (i)
            {
                case 0:
                    return (new ShrubberyCreationForm(target));
                case 1:
                    return (new RobotomyRequestForm(target));
                case 2:
                    return (new PresidentialPardonForm(target));
            }
        }
    }
    std::cout << "[ERROR] Intern cannot make " << formName << " form" << std::endl;
    return (NULL);
}