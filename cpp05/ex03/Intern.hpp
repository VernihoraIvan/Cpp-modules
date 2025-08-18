/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:15:20 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/18 14:09:31 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);

        AForm *makeForm(std::string formName, std::string target);

        private:
		Intern &operator=(const Intern &other);

};
#endif