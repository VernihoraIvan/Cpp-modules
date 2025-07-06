/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:25:37 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:11:53 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing Animal Polymorphism ===" << std::endl;

	// Test polymorphism with Animal base class
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Animal type: " << meta->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\nMaking sounds:" << std::endl;
	meta->makeSound(); // Should make generic animal sound
	dog->makeSound();  // Should bark
	cat->makeSound();  // Should meow

	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n=== Testing WrongAnimal (No Polymorphism) ===" << std::endl;

	// Test wrong implementation without proper virtual functions
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongAnimal type: " << wrongMeta->getType() << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

	std::cout << "\nMaking sounds (should show polymorphism issue):" << std::endl;
	wrongMeta->makeSound(); // Should make generic animal sound
	wrongCat->makeSound();  // Should also make generic animal sound (not cat sound!)

	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n=== Testing Direct Object Creation ===" << std::endl;

	// Test direct object creation (not through pointers)
	Dog directDog;
	Cat directCat;
	WrongCat directWrongCat;

	std::cout << "Direct dog sound: ";
	directDog.makeSound();
	std::cout << "Direct cat sound: ";
	directCat.makeSound();
	std::cout << "Direct wrong cat sound: ";
	directWrongCat.makeSound();

	return 0;
}
