/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:48:32 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/02 11:49:09 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = copy.getRawBits();
}

Fixed::Fixed(const int new_value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = new_value << _fractbits;
}

Fixed::Fixed(const float new_value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(new_value * (1 << _fractbits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractbits);
}

int	Fixed::toInt(void) const
{
	return _value >> _fractbits;
}

std::ostream&	operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return os;
}