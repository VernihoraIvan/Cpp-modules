/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:25:39 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/08 15:13:48 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>
#include <ostream>

int main(void)
{
    try
    {
      std::cout << "--------------------------------" << std::endl;
      PresidentialPardonForm form1("target");
      Bureaucrat bureaucrat1("bureaucrat1", 1);
      form1.beSigned(bureaucrat1);
      form1.execute(bureaucrat1);
      std::cout << form1 << std::endl;
      std::cout << "--------------------------------" << std::endl;
      RobotomyRequestForm form2("target");
      Bureaucrat bureaucrat2("bureaucrat2", 10);
      form2.beSigned(bureaucrat2);
      form2.execute(bureaucrat2);
      std::cout << form2 << std::endl;
      std::cout << "--------------------------------" << std::endl;
      ShrubberyCreationForm form3("target");
      Bureaucrat bureaucrat3("bureaucrat3", 1);
      form3.beSigned(bureaucrat3);
      form3.execute(bureaucrat3);
      std::cout << form3 << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }
    
}