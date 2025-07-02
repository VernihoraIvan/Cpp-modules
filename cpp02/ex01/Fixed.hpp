/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:48:34 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/07/02 12:16:37 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
#include <iostream>
#include <cmath>

class Fixed
{
  public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);
	Fixed &operator=(const Fixed &copy);
    float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int _value;
	static const int _fractbits = 8;
};

std::ostream&	operator<<(std::ostream &os, const Fixed &fix);


#endif