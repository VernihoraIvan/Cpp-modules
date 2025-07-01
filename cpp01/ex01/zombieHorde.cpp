/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:11:02 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/01 13:10:42 by iverniho         ###   ########.fr       */
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
        std::stringstream ss;
        ss << i;
        std::string ranked_name = name + "_" + ss.str();
        zombies[i].baptize(ranked_name);
    }
    return (zombies);
}
