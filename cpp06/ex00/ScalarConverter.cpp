/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:53:20 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/09/01 10:58:37 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <sstream>
#include <climits>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}   

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

static float _stof(const std::string &str)
{
    std::string cleanStr = str;
    if (!cleanStr.empty() && cleanStr.back() == 'f')
        cleanStr.pop_back();  
    float num;
    std::stringstream stream(cleanStr);
    stream >> num;
    return num;
}

static double _stod(const std::string &str)
{
    double num;
    std::stringstream stream(str);
    stream >> num;
    return num;
}

void printChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printInt(double nbr)
{
    if (nbr >= 32 && nbr < 127)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
    if (nbr > INT_MAX || nbr < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

int calcPrecision(const std::string &src)
{
    size_t dotPos = src.find('.');
    int precision = 1;
    if (dotPos != std::string::npos)
    {
        precision = src.length() - dotPos - 1;
        if (precision > 15)
            precision = 15;
    }
    return precision;
}

void printDouble(const std::string &src)
{
    double nbr = _stod(src);
    if (nbr >= 32 && nbr < 127)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
    if (nbr > INT_MAX || nbr < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    
    int precision = calcPrecision(src);
    
    if (nbr == static_cast<int>(nbr))
        std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(precision) << "float: " << static_cast<float>(nbr) << "f" << std::endl;
    
    if (nbr == static_cast<int>(nbr))
        std::cout << "double: " << nbr << ".0" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(precision) << "double: " << nbr << std::endl;
    
    std::cout.unsetf(std::ios_base::floatfield);
}

void printFloat(const std::string &src)
{
    float nbr = _stof(src);
    double checkIntOverflow = std::stod(src);

    if (nbr >= 32 && nbr < 127)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
    if (checkIntOverflow > INT_MAX || checkIntOverflow < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;

    int precision = calcPrecision(src);
    
    if (nbr == static_cast<int>(nbr))
        std::cout << "float: " << nbr << ".0f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(precision) << "float: " << nbr << "f" << std::endl;
    
    if (static_cast<double>(nbr) == static_cast<int>(nbr))
        std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(precision) << "double: " << static_cast<double>(nbr) << std::endl;
    
    std::cout.unsetf(std::ios_base::floatfield);
}

void printPseudoLiteral(const std::string &src)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (src == "nanf") 
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (src == "+inff") 
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (src == "-inff") 
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (src == "nan") 
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (src == "+inf") 
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (src == "-inf") 
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

bool isPseudoLiteral(const std::string &src)
{
    return (src == "nan" || src == "nanf" || src == "+inf" || src == "-inf" || src == "+inff" || src == "-inff");
}

bool isInt(const std::string &src)
{
    bool isInt = false;
    int index = 1;
    index = src[0] == '-' ? 1 : 0;

    for (size_t i = index; i < src.length(); i++)
    {
        if (isdigit(src[i]))
            isInt = true;
        else
            return false;
    }
    return isInt;
}

bool isChar(const std::string &src)
{
    return (src.length() == 1 && std::isprint(src[0]));
}

bool isFloat(const std::string &src)
{
    if (src.empty() || src.back() != 'f')
        return false;

    std::string str = src.substr(0, src.length() - 1);
    if (str.empty())
        return false;

    size_t i = 0;
    if (str[i] == '-' || str[i] == '+') 
        i++;

    bool hasDot = false;
    bool hasDigit = false;

    for (; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            hasDigit = true;
        else if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else
            return false;
    }
    return hasDigit && hasDot;
}

bool isDouble(const std::string &src)
{
    if (src.empty() || src.back() == 'f')
        return false;
    int index = 1;
    index = src[0] == '-' || src[0] == '+' ? 1 : 0;

    bool hasDigit = false;
    bool hasDot = false;
    if (index == 1 && src.length() == 1) 
        return false;

    for (size_t i = index; i < src.length(); i++)
    {
        if (isdigit(src[i])) 
            hasDigit = true;
        else if (src[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else
            return false;
    }
    return hasDigit && hasDot;
}

Type getType(const std::string &src)
{
    if (isChar(src))
        return CHAR;
    else if (isInt(src))
        return INT;
    else if (isFloat(src))
        return FLOAT;
    else if (isDouble(src))
        return DOUBLE;
    else if (isPseudoLiteral(src))
        return PSEUDO_LITERAL;
    else
        return UNKNOWN;
}

void ScalarConverter::convert(const std::string &src)
{
    switch (getType(src))
    {
        case CHAR:
            printChar(src[0]);
            break;
        case INT:
            printInt(_stod(src));
            break;
        case FLOAT:
            printFloat(src);
            break;
        case DOUBLE:
            printDouble(src);
            break;
        case PSEUDO_LITERAL:
            printPseudoLiteral(src);
            break;
        case UNKNOWN:
            std::cout << "Unknown type" << std::endl;
            break;
    }
    
}