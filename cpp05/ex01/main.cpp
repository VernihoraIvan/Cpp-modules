/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:25:39 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/07 11:54:26 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>
#include <ostream>

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("John", 111);
        Bureaucrat bureaucrat2("Jane", 10);
        Bureaucrat bureaucrat3("Jim", 50);
        Bureaucrat bureaucrat4("Jack", 100);

        //throws exception because grade is out of range
        // Bureaucrat bureaucrat3("Jim", 151);

        std::cout << bureaucrat << std::endl;
        std::cout << bureaucrat2 << std::endl;

        Form form("Form1", 10, 100);
        Form form2("Form2", 10, 10);
        Form form3("Form3", 50, 40);
        Form form4("Form4", 100, 90);

        // throws exception because grade is too low
        // form.beSigned(bureaucrat);
        form2.beSigned(bureaucrat2);
        form2.beSigned(bureaucrat2);
        // throws exception because grade is too low
        // form3.beSigned(bureaucrat3);
        form4.beSigned(bureaucrat4);

        // could not execute because form is not signed
        form.execute(bureaucrat);
        form2.execute(bureaucrat2);
        form3.execute(bureaucrat3);
        // throws exception because grade is too low
        // form4.execute(bureaucrat4);
        
        std::cout << form << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        std::cout << form4 << std::endl;
       
        std::cout << bureaucrat << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << bureaucrat3 << std::endl;
        std::cout << bureaucrat4 << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }
    
}