/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:06:32 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/02 15:00:26 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);

	// Test increment/decrement
	std::cout << "=== Increment/Decrement ===" << std::endl;
	std::cout << "a: " << a << " -> ++a: " << ++a << " -> a++: " << a++ << " -> a: " << a << std::endl;
	std::cout << "a: " << a << " -> --a: " << --a << " -> a--: " << a-- << " -> a: " << a << std::endl;
	
	// Test arithmetic operators
	std::cout << "\n=== Arithmetic Operations ===" << std::endl;
	std::cout << b << " + " << c << " = " << (b + c) << std::endl;
	std::cout << b << " - " << c << " = " << (b - c) << std::endl;
	std::cout << b << " * " << c << " = " << (b * c) << std::endl;
	std::cout << b << " / " << c << " = " << (b / c) << std::endl;

	// Test comparison operators
	std::cout << "\n=== Comparison Operations ===" << std::endl;
	Fixed d(5.05f);
	std::cout << b << " == " << d << ": " << (b == d) << std::endl;
	std::cout << b << " != " << c << ": " << (b != c) << std::endl;
	std::cout << b << " > " << c << ": " << (b > c) << std::endl;
	std::cout << b << " < " << c << ": " << (b < c) << std::endl;
	std::cout << b << " >= " << d << ": " << (b >= d) << std::endl;
	std::cout << c << " <= " << b << ": " << (c <= b) << std::endl;

	// Test min/max functions
	std::cout << "\n=== Min/Max Functions ===" << std::endl;
	std::cout << "min(" << b << ", " << c << ") = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(" << b << ", " << c << ") = " << Fixed::max(b, c) << std::endl;

	// Test assignment and loop
	std::cout << "\n=== Assignment & Loop Test ===" << std::endl;
	Fixed i = Fixed(0);
	Fixed end(0.02f);
	std::cout << "Counting from 0 to " << end << ": ";
	while (i <= end) {
		std::cout << i;
		if (++i <= end) std::cout << ", ";
	}
	std::cout << std::endl;

	return (0);
}
