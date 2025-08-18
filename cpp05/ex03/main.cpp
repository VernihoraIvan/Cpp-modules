/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:25:39 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/18 14:14:23 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>
#include <ostream>

int main(void)
{
    try
    {
      std::cout << "--------------------------------" << std::endl;
      Bureaucrat turtle("Turtle", 1);
      Intern intern;
      AForm *formS = intern.makeForm("shrubbery creation", "Turtle");
      // AForm *formR = intern.makeForm("robotomy request", "Bender");
      // AForm *formP = intern.makeForm("presidential pardon", "Lesly");

      //wrong request
      AForm *formW = intern.makeForm("wrong request", "Marvin");
		  delete formW;

      formS->beSigned(turtle);
      formS->execute(turtle);
      // formR->beSigned(turtle);
      // formR->execute(turtle);
      // formP->beSigned(turtle);
      // formP->execute(turtle);

      delete formS;
      // delete formR;
      // delete formP;
      std::cout << "--------------------------------" << std::endl;
      
    }
    catch(const std::exception& e)
    {
		std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }
    
}