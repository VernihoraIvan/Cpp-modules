/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:28:28 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 15:08:23 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const std::string &type);
		~Cat();
		Cat(const Cat &copy);

		Cat &operator=(const Cat &copy);

		void makeSound(void) const;
		std::string getType(void) const;

	private:
		std::string type;
};

#endif
