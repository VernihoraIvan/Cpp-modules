/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:36:43 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/02 23:55:03 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// Basic constructor and actions test
	ScavTrap scav("Warrior");
	scav.guardGate();
	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(15);
	
	// Copy constructor test
	ScavTrap scav2(scav);
	scav2.attack("Target");
	
	// Assignment operator test
	ScavTrap scav3("Original");
	scav3 = scav;
	scav3.guardGate();
	
	// Energy depletion test
	ScavTrap energyTest("EnergyTest");
	for (int i = 0; i < 51; i++) // ScavTrap has 50 energy
		energyTest.attack("Dummy");
	
	// Death test
	ScavTrap mortal("Mortal");
	mortal.takeDamage(100); // Fatal damage
	mortal.attack("Ghost"); // Should fail
	
	return (0);
}