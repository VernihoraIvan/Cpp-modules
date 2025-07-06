/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:41:56 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:11:40 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

		WrongAnimal &operator=(const WrongAnimal &copy);

		std::string getType(void) const;
		void makeSound(void) const;

	protected:
		std::string _type;

};

#endif

