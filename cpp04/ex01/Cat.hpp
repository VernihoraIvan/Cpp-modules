/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:28:28 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 16:49:13 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const std::string &type);
		virtual ~Cat();
		Cat(const Cat &copy);

		Cat &operator=(const Cat &copy);

		void makeSound(void) const;
		std::string getType(void) const;
		void setIdea(const std::string &idea);
		void getIdeas(void) const;

	private:
		std::string _type;
		Brain *brain;

};

#endif
