/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:11:14 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 01:43:07 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
    public:
		HumanB(std::string name);
		~HumanB( void );
		void	attack(void);
		void setWeapon(Weapon &new_weapon);

	private:
		HumanB(void);
        std::string name;
		// The weapon is a pointer because a HumanB might not always have a weapon.
		// A pointer can be null, whereas a reference must be initialized.
        Weapon *weapon;
};

#endif