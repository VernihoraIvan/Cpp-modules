/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:27:37 by iverniho          #+#    #+#             */
/*   Updated: 2025/07/06 16:56:19 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);

		Brain &operator=(const Brain &copy);

		void getIdeas(void) const;
		void setIdea(const std::string &idea);

	private:
		std::string ideas[100];
};

#endif
