/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:11:21 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 01:18:01 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
public:
    Weapon(void);
    Weapon(const std::string &type);
    ~Weapon(void);

    const std::string getType(void) const;
    void setType(const std::string &new_type);

private:
    std::string type;
};

#endif