/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:11:12 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 00:27:38 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
    public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA( void );
		void	attack(void);

	private:
        std::string name;
        Weapon &weapon;
};

#endif