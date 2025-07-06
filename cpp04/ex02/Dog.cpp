/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:57 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 16:49:31 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type), brain(new Brain()) {
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

std::string Dog::getType(void) const {
	return this->_type;
}

void Dog::makeSound(void) const {
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(const std::string &idea) {
	if (brain) {
		brain->setIdea(idea);
	}
}

void Dog::getIdeas(void) const {
	if (brain) {
		brain->Brain::getIdeas();
		return ;
	}
	return;
}
