/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:11:02 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/26 23:11:04 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "Invalid number of zombies" << std::endl;
        return (NULL);
    }
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        std::string ranked_name = name + "_" + std::to_string(i);
        zombies[i].baptize(ranked_name);
    }
    return (zombies);
}