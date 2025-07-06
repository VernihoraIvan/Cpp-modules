/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:45:04 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:09:37 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string const &type);
		WrongCat(const WrongCat &copy);
		~WrongCat();

		WrongCat &operator=(const WrongCat &copy);

		void makeSound(void) const;
		std::string getType(void) const;

	private:
		std::string type;
};

#endif
