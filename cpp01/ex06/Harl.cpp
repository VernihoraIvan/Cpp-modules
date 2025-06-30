/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:16:17 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/30 21:59:34 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	parameters_list[0] = "DEBUG";
	parameters_list[1] = "INFO";
	parameters_list[2] = "WARNING";
	parameters_list[3] = "ERROR";
}

Harl::~Harl( void ) {
	return;
}

void    Harl::debug( void ) {
	std::cout << "[DEBUG]" << std:: endl;
	std::cout << "I love having extra bacon for my" << std::endl;
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void    Harl::info( void ) {
	std::cout << "[INFO]" << std:: endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did,\n I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
	std::cerr << "[WARNING]" << std:: endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error( void ) {
	std::cerr  <<  "[ERROR]" << std:: endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now.";
	std::cerr << std:: endl;
}

void Harl::complain(std::string parameter)
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (parameters_list[i] == parameter)
            break;
    }

    switch (i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}