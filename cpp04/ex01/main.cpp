/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:30:00 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 17:21:39 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <sstream>

int main() {
	std::cout << "=== Creating array of Animals ===" << std::endl;
	const int size = 10;
	Animal* animals[size];

	// Fill half with Dogs and half with Cats
	for (int i = 0; i < size / 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = size / 2; i < size; i++) {
		animals[i] = new Cat();
	}

	std::cout << "\n=== Testing Brain functionality ===" << std::endl;
	Dog* dog = dynamic_cast<Dog*>(animals[0]);
	if (dog) {
		for (int i = 0; i < 3; i++) {
			std::stringstream ss;
			ss << "Dog idea " << (i + 1);
			dog->setIdea(ss.str());
		}
		std::cout << "First dog's ideas: ";
		dog->getIdeas();
	}

	Cat* cat = dynamic_cast<Cat*>(animals[5]);
	if (cat) {
		for (int i = 0; i < 3; i++) {
			std::stringstream ss;
			ss << "Cat thought " << (i + 1);
			cat->setIdea(ss.str());
		}
		std::cout << "First cat's ideas: ";
		cat->getIdeas();
	}

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog originalDog;
	originalDog.setIdea("Original idea");
	Dog copiedDog = originalDog;
	copiedDog.setIdea("Copied idea");

	std::cout << "Original dog ideas: ";
	originalDog.getIdeas();
	std::cout << "Copied dog ideas: ";
	copiedDog.getIdeas();

	std::cout << "\n=== Deleting all animals ===" << std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}

	std::cout << "\n=== End of program ===" << std::endl;
	return 0;
}
