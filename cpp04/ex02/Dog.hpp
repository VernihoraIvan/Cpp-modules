/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:59 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 16:36:50 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &copy);
		virtual ~Dog();

		Dog &operator=(const Dog &copy);

		void makeSound(void) const;
		std::string getType(void) const;
		void setIdea(const std::string &idea);
		void getIdeas(void) const;

	private:
		std::string _type;
		Brain *brain;
};

#endif
