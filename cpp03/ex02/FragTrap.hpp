/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:34:38 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/04 12:10:14 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>


class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap(void);

        void highFivesGuys(void);
        void attack(const std::string &target);

    private:
        int _highFives;
};

#endif