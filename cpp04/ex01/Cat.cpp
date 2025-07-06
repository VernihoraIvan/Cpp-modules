/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:30:50 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 16:50:48 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type), brain(new Brain()) {
	std::cout << "Cat parameterized constructor called" << std::endl;
}


Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

std::string Cat::getType(void) const {
	return this->_type;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(const std::string &idea) {
	if (brain) {
		brain->setIdea(idea);
	}
}

void Cat::getIdeas(void) const {
	if (brain) {
		brain->Brain::getIdeas();
		return ;
	}
	return;
}

