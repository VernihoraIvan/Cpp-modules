/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:38:55 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/04 12:41:48 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Clappy"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this == &rhs)
    {
        std::cout << "Self-assignment detected" << std::endl;
        return (*this);
    }
    this->_name = rhs._name;
    this->_hit_points = rhs._hit_points;
    this->_energy_points = rhs._energy_points;
    this->_attack_damage = rhs._attack_damage;
    
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}


void ClapTrap::attack(const std::string &target)
{
    if (_hit_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack" << std::endl;
        return ;
    }
    if (_energy_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy and can't attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
    std::cout << "ClapTrap " << _name << " has " << _hit_points << " hit points and " << _energy_points << " energy points" << std::endl;
    _energy_points--;
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
        return ;
    }
    int damage = static_cast<int>(amount);
    _hit_points -= damage;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (_hit_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead" << std::endl;
        return ;
    }
    else
        std::cout << "ClapTrap " << _name << " has " << _hit_points << " hit points and " << _energy_points << " energy points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't be repaired" << std::endl;
        return ;
    }
    if (_energy_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to be repaired" << std::endl;
        return ;
    }
    int repair = static_cast<int>(amount);
    _hit_points += repair;
    _energy_points--;
    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
    std::cout << "ClapTrap " << _name << " has " << _hit_points << " hit points and " << _energy_points << " energy points" << std::endl;
    return;
}

std::string ClapTrap::getName(void) const
{
    return (_name);
}

int ClapTrap::getAttackDamage(void) const
{
    return (_attack_damage);
}

void ClapTrap::setAttackDamage(int amount)
{
    if (amount > 0)
        _attack_damage = amount;
}