/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:37:27 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 01:17:43 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return;
}

Weapon::Weapon(const std::string &type)
{
    this->setType(type);
    return;
}

Weapon::~Weapon(void)
{
    return;
}

const std::string Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(const std::string &new_type)
{
    this->type = new_type;
    return;
}