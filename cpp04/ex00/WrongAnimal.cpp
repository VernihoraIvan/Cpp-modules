/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:41:53 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:00:02 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &copy) {
		_type = copy._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return _type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

