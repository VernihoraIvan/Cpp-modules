/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:08:37 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/05 13:26:17 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    return;
}

Fixed::Fixed(const Fixed &copy)
{
    _value = copy.getRawBits();
    return;
}

Fixed::Fixed(const int value) : _value(value << _fractbits)
{
    return;
}

Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _fractbits))))
{
    return;
}

Fixed::~Fixed(void)
{
    return;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        _value = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
    return;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractbits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractbits;
}


// Comparison operators
bool Fixed::operator==(const Fixed &a) const
{
    return _value == a.getRawBits();
}

bool Fixed::operator!=(const Fixed &a) const
{
    return _value != a.getRawBits();
}

bool Fixed::operator>(const Fixed &a) const
{
    return _value > a.getRawBits();
}

bool Fixed::operator>=(const Fixed &a) const
{
    return _value >= a.getRawBits();
}

bool Fixed::operator<(const Fixed &a) const
{
    return _value < a.getRawBits();
}

bool Fixed::operator<=(const Fixed &a) const
{
    return _value <= a.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &a) const
{
    return Fixed((*this).toFloat() + a.toFloat());
}

Fixed Fixed::operator-(const Fixed &a) const
{
    return Fixed((*this).toFloat() - a.toFloat());
}

Fixed Fixed::operator*(const Fixed &a) const
{
    return Fixed((*this).toFloat() * a.toFloat());
}

Fixed Fixed::operator/(const Fixed &a) const
{
    if (a._value == 0)
	{
		std::cout << "Cannot divide by zero" << std::endl;
		return *this;
	}
    return Fixed((*this).toFloat() / a.toFloat());
}

// Increment/decrement operators
Fixed &Fixed::operator++()
{
    (*this)._value++;
    return *this;
}

Fixed Fixed::operator++(int i)
{
    (void)i;
    Fixed copy = *this;
    ++(*this);
    return copy;
}

Fixed &Fixed::operator--()
{
    (*this)._value--;
    return *this;
}

Fixed Fixed::operator--(int i)
{
    (void)i;
    Fixed copy = *this;
    --(*this);
    return copy;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed  &a,const Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &a)
{
	os << a.toFloat();
	return os;
}
