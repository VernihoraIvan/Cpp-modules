/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:16:19 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/30 21:27:21 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "You have to pass a filter parameter " << std::endl;
        std::cout << "List of available parameters: WARNING, DEBUG, INFO, ERROR." << std::endl;
        return (1);
    }

    std::string parameter = argv[1];
    Harl harl;
    harl.complain(parameter);
    
    return(0);
}