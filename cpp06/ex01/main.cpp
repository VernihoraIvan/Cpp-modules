/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:07:54 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/09/01 12:21:58 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data *data = new Data("Ivan", 42);
	
    std::cout << "Data address: " << data << std::endl;
	std::cout << "Data string: " << data->name << std::endl;
    std::cout << "Data value: " << data->value << std::endl;
	
	uintptr_t s_data = Serializer::serialize(data);
	std::cout << "Serialized data is: " << s_data << std::endl;

	Data *ds_data = Serializer::deserialize(s_data);
	std::cout << "Data address:   " << ds_data << std::endl;
    std::cout << "Data value: " << ds_data->value << std::endl;

	std::cout << "Data string: " << ds_data->name << std::endl;

    delete data;
    return 0;
}
