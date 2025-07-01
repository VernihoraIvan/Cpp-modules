/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:10:56 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/01 13:10:49 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <ostream>
#include <iostream>
#include <sstream>

class Zombie
{
  public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
	void baptize(std::string name);

  private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
