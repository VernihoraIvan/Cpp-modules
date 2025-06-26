/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:10:46 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/26 23:10:48 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <ostream>
#include <iostream>

class Zombie
{
  public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);

  private:
	std::string name;
	Zombie(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif