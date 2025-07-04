/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:47:57 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/04 12:45:47 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &src)
        ClapTrap::operator=(src);
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hit_points <= 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and can't attack" << std::endl;
        return ;
    }
    if (_energy_points <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy points left to attack" << std::endl;
        return ;
    }
    _energy_points--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
    std::cout << "ScavTrap " << _name << " has " << _hit_points << " hit points and " << _energy_points << " energy points" << std::endl;
}

