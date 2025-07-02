/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:36:43 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/02 22:25:02 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Test 1: Basic functionality ===" << std::endl;
	ClapTrap robot1("Alpha");
	robot1.setAttackDamage(3);
	
	robot1.attack("training dummy");
	robot1.takeDamage(5);
	robot1.beRepaired(2);
	robot1.attack("another target");

	std::cout << "\n=== Test 2: Energy depletion ===" << std::endl;
	ClapTrap robot2("Beta");
	robot2.setAttackDamage(1);
	
	// Use up all energy points (10 attacks)
	for (int i = 0; i < 11; i++)
		robot2.attack("enemy");

	std::cout << "\n=== Test 3: Death and revival attempt ===" << std::endl;
	ClapTrap robot3("Gamma");
	robot3.setAttackDamage(2);
	
	robot3.takeDamage(15); 
	robot3.attack("ghost target"); 
	robot3.beRepaired(5);
	robot3.takeDamage(5);

	std::cout << "\n=== Test 4: Copy constructor and assignment ===" << std::endl;
	ClapTrap original("Original");
	original.setAttackDamage(4);
	
	ClapTrap copy1(original); 
	ClapTrap copy2 = original; 
	
	std::cout << "Original name: " << original.getName() << std::endl;
	std::cout << "Copy1 name: " << copy1.getName() << std::endl;
	std::cout << "Copy2 name: " << copy2.getName() << std::endl;
	
	copy1.attack("target1");
	copy2.attack("target2");

	std::cout << "\n=== Test 5: Default constructor ===" << std::endl;
	ClapTrap defaultBot;
	std::cout << "Default bot name: " << defaultBot.getName() << std::endl;
	defaultBot.setAttackDamage(1);
	defaultBot.attack("test target");
	
	return (0);
}