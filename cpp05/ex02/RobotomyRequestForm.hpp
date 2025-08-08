/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:55:54 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 15:35:07 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include <cstdlib>
#include <ctime>

#define ROBOTOMY_SIGN_LEVEL 72
#define ROBOTOMY_EXECUTE_LEVEL 45

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm(void);

        const std::string &getTarget(void) const;
        virtual void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const;

    private:
        RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif