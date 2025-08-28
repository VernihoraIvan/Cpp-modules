/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:53:22 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/28 14:57:35 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    UNKNOWN
} Type;

class ScalarConverter
{
    public:
        static void convert(const std::string &src);

    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter(void);
};

#endif