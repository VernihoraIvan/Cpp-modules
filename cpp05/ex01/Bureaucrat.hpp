/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:42:47 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/07 11:44:35 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ostream>

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat(void);

        const std::string &getName(void) const;
        int getGrade(void) const;

        void incrementGrade(void);
        void decrementGrade(void);

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
        Bureaucrat(void);
        Bureaucrat &operator=(const Bureaucrat &copy);
        
        const std::string _name;
        int _grade;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif