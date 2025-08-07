/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:25:39 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/06 16:21:49 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <ostream>

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("John", 150);
        Bureaucrat bureaucrat2("Jane", 1);
        Bureaucrat bureaucrat3(bureaucrat);

        //throws exception
        // Bureaucrat bureaucrat4("Jim", 151);
        // Bureaucrat bureaucrat6 = bureaucrat;

        std::cout << bureaucrat << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << bureaucrat3 << std::endl;
        // std::cout << bureaucrat4 << std::endl;
        // std::cout << bureaucrat5 << std::endl;

        //throws exception
        // bureaucrat.decrementGrade();
        bureaucrat3.incrementGrade();
        //throws exception
        // bureaucrat2.incrementGrade();
        std::cout << bureaucrat << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << bureaucrat3 << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }
    
}