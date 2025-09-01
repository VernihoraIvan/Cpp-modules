/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:48:31 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/09/01 12:06:39 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
	public:
		Data(void);
		Data(const Data &other);
		Data(std::string name, int value);
		Data &operator=(const Data &other);
		~Data(void);

        std::string name;
        int value;
};

#endif