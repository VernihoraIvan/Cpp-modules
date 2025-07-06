/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:46:51 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:05:47 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string const &type) : WrongAnimal(type) {
	std::cout << "WrongCat parameterized constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &copy) {
		WrongAnimal::operator=(copy);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongMeow!" << std::endl;
}

std::string WrongCat::getType(void) const {
	return this->_type;
}
