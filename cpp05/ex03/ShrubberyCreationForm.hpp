/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:55:58 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 15:02:32 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include <fstream>

#define SHRUBBERY_SIGN_LEVEL 145
#define SHRUBBERY_EXECUTE_LEVEL 137

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm(void);

        void generateTree(void) const;
        const std::string &getTarget(void) const;
        virtual void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const;

    private:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif