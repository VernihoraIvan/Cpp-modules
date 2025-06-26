/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:34:16 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 01:50:40 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    if (this->name.length() == 0)
        this->name = "HumanB";
    return;
}

HumanB::HumanB(void) : weapon(NULL)
{
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << std::endl << this->weapon->getType() << std::endl;
    else
         std::cout << this->name << " attacks with their hands " << std::endl;

}

void HumanB::setWeapon(Weapon &new_weapon)
{
    this->weapon = &new_weapon;
    return;
}