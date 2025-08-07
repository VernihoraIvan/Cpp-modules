/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:05:14 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/07 11:44:49 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <ostream>

class Form
{
    public:
        Form(void);
        Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &copy);
        ~Form(void);

        const std::string &getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(const Bureaucrat &executor) const;

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
        Form &operator=(const Form &copy);
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif