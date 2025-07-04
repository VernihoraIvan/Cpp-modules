/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:34:42 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/04 12:24:02 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    _highFives = 0;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called for " << name << std::endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    _highFives = 0;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &src)
        ClapTrap::operator=(src);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " is requesting a high five" << std::endl;
    _highFives++;
    std::cout << "FragTrap " << _name << " has " << _highFives << " high fives" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_hit_points <= 0)
    {
        std::cout << "FragTrap " << _name << " is dead and can't attack" << std::endl;
        return ;
    }
    if (_energy_points <= 0)
    {
        std::cout << "FragTrap " << _name << " has no energy points left to attack" << std::endl;
        return ;
    }
    _energy_points--;
    std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
    std::cout << "FragTrap " << _name << " has " << _hit_points << " hit points and " << _energy_points << " energy points" << std::endl;
}