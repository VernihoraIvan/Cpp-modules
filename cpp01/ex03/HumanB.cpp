/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:34:16 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 01:30:19 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    return;
}

HumanB::HumanB(void)
{
	return;
}

HumanB::~HumanB( void )
{
    return;
}

void HumanB::attack(void)
{
	std::cout << HumanB::name << " attacked with: " << std::endl << HumanB::weapon.getType()  << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
    this->weapon = new_weapon;
    return;
}