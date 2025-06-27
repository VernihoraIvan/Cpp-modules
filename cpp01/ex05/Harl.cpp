/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:19:01 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 12:31:36 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    return;
}

Harl::~Harl( void ) {
	return;
}

void    Harl::debug( void ) {
	std::cout << "DEBUG:" << std:: endl;
	std::cout << "I love having extra bacon for my" << std::endl;
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void    Harl::info( void ) {
	std::cout << "INFO:" << std:: endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did,\n I wouldn't be asking for more!" << std::endl;

}

void    Harl::warning( void ) {
	std::cerr << "WARNING:" << std:: endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas " << std::endl;
	std::cout << "ou started working here just last month." << std::endl;

}

void    Harl::error( void ) {
	std::cerr  <<  "ERROR:" << std:: endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now.";
	std::cerr << std:: endl;
}

void	Harl::complain(std::string level) {
	
	std::cout << std::endl;
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	stages[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (stages[i] == level) {
			(this->*f[i])();
		}
	}
}