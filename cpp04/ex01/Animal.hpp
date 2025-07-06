/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:29:26 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:07:39 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:

		Animal(void);
		Animal(const std::string &type);
		virtual ~Animal();
		Animal(const Animal &copy);

		Animal &operator=(const Animal &copy);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string _type;

};

#endif
