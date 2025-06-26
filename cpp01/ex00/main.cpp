/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:10:36 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/26 23:10:37 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
   std::cout << "Zombies on heap: " << std::endl;

	Zombie *ptrZombie_1 = newZombie("heap_Erik");
	Zombie *ptrZombie_2 = newZombie("heap_John");

	std::cout << std::endl << "Zombies on stack: " << std::endl;

	randomChump("stack_Anna");
	randomChump("stack_Mia");

	std::cout << std::endl << "Only now heap zombies are dead: " << std::endl;

	delete ptrZombie_1;
	delete ptrZombie_2;

	return (0);
}