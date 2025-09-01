/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:48:39 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/09/01 12:07:08 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{
	public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    
    private:
        Serializer(void);
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer(void);
};

#endif