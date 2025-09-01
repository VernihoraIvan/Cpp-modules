/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:48:29 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/09/01 12:05:28 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : name("Jane"), value(10)
{
}

Data::Data(const Data &other) : name(other.name), value(other.value)
{
}

Data::Data(std::string name, int value) : name(name), value(value)
{
}

Data::~Data(void)
{
}

Data &Data::operator=(const Data &other)
{
    name = other.name;
    value = other.value;
    return *this;
}
