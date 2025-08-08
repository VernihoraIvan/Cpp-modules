/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:05:14 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 15:31:47 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <ostream>

class AForm
{
    public:
        AForm(void);
        AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &copy);
        virtual ~AForm(void);

        const std::string &getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const = 0;

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

    private:
        AForm &operator=(const AForm &copy);
    
    protected:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif