/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:09:11 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 01:14:58 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void HumanA::attack(void)
{
    std::cout << HumanA::name  << " attacked with: " << std::endl << HumanA::weapon.getType() << std::endl;
}