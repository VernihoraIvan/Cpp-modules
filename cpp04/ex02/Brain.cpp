/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:58 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 16:47:33 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}

void Brain::getIdeas(void) const {
	for (int i = 0; i < 100; ++i) {
		if (!ideas[i].empty()) {
			std::cout << "Idea at index " << i << ": " << ideas[i] << std::endl;
			return;
		}
	}
	std::cout << "No ideas found" << std::endl;
	return;
}

void Brain::setIdea(const std::string &idea)
{
	
	for (int i = 0; i < 100; i++)
	{
		if (this->ideas[i].empty())
		{
			this->ideas[i] = idea;
			std::cout << "New idea: " << idea << std::endl;
			return;
		}
	}
	std::cout << "Array of ideas has reached its limit" << std::endl;
	return;
}

