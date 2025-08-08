/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:55:49 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 14:42:12 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <ostream>

#define PRESIDENTIAL_SIGN_LEVEL 25
#define PRESIDENTIAL_EXECUTE_LEVEL 5

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm(void);

        const std::string &getTarget(void) const;
        virtual void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const;

    private:
        PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif
