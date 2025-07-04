/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:36:43 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/04 12:40:31 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- FragTrap Tests ---" << std::endl;
	// Basic constructor and actions test
	FragTrap frag("Destroyer");
	FragTrap frag2("Enemy");
	frag.highFivesGuys();
	frag.attack("Enemy");

	frag2.takeDamage(30);
	frag2.beRepaired(20);
	std::cout << std::endl;

	// Copy constructor test
	FragTrap frag3(frag);
	frag3.attack("Another Target");
	std::cout << std::endl;
	
	// Assignment operator test
	FragTrap frag4("OriginalFrag");
	frag4 = frag;
	frag4.highFivesGuys();
	std::cout << std::endl;
	
	// Energy depletion test
	FragTrap energyTestFrag("EnergyTestFrag");
	 // FragTrap has 100 energy
	for (int i = 0; i < 101; i++)
		energyTestFrag.attack("Dummy");
	std::cout << std::endl;

	// Death test
	FragTrap mortalFrag("MortalFrag");
	// Fatal damage
	mortalFrag.takeDamage(100); 
	// Should fail
	mortalFrag.attack("Zombie"); 
	std::cout << std::endl;
	
	return (0);
}