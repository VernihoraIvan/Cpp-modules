/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:39:05 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/04 12:43:32 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(const std::string &name);
        ClapTrap(ClapTrap const &src);
        ClapTrap &operator=(ClapTrap const &rhs);
        // When you have a class hierarchy and you don't have a virtual destructor, you can run into undefined behavior.
        virtual ~ClapTrap(void);

        std::string getName(void) const;
        int getAttackDamage(void) const;
        void setAttackDamage(int amount);

        virtual void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;

};

#endif