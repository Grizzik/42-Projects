/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:14:26 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/04 22:12:12 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

const int Fixed::_nbits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n) : _value(n << _nbits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _nbits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &toCopy)
		*this = toCopy;
	return ;
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float(_value) / (1 << _nbits)); //diviser par 2^(_nbits) revient à décaler la virgule fixe vers la gauche de _nbits positions
}


int	Fixed::toInt(void) const
{
	return (_value >> _nbits);
}

Fixed& Fixed::operator=(const Fixed &toCopy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &toCopy)
        this->_value = toCopy.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}
