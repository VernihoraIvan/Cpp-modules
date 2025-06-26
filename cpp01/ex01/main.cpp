/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:10:50 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/26 23:10:51 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
   int N = 5;
   Zombie *zombies = zombieHorde(N, "Zombie");

   std::cout << "Zombies awaken and announce themselves: " << std::endl;
   for (int i = 0; i < N; i++)
   {
      zombies[i].announce();
   }
   delete[] zombies;

	return (0);
}