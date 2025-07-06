/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:35:09 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:07:34 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copy) {
		_type = copy._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const {
	return _type;
}

void Animal::makeSound(void) const {
	std::cout << "Animal makes a sound" << std::endl;
}

