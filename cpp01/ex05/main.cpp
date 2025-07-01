/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:18:08 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/01 13:28:34 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int  main () {

    Harl harl;

	harl.complain("ERROR");
	harl.complain("WARNING");
    harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("");

    return 0;
}
