/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:30:50 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:07:46 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type) {
	std::cout << "Cat parameterized constructor called" << std::endl;
}


Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
	}
	return *this;
}

std::string Cat::getType(void) const {
	return _type;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}
