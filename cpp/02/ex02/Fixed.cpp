/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:06:36 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/04 22:59:30 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nb(0)
{
}

Fixed::Fixed(const int n) : _nb(n << _bits)
{
}

Fixed::Fixed(const float f) : _nb(roundf(f * (1 << _bits))) 
{
}

Fixed::Fixed (const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed(){
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	_nb = copy.getRawBits();
	return(*this);
}

bool	Fixed::operator<(const Fixed &Class) const
{
	if (this->_nb < Class._nb)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &Class) const
{
	if (this->_nb <= Class._nb)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &Class) const
{
	if (this->_nb > Class._nb)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &Class) const
{
	if (this->_nb >= Class._nb)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &Class) const
{
	if (this->_nb == Class._nb)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &Class) const
{
	if (this->_nb != Class._nb)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &Class) const
{
	return (this->toFloat() + Class.toFloat());
}

Fixed	Fixed::operator*(const Fixed &Class) const
{
	return (this->toFloat() * Class.toFloat());
}

Fixed	Fixed::operator-(const Fixed &Class) const
{
	return (this->toFloat() - Class.toFloat());
}

Fixed	Fixed::operator/(const Fixed &Class) const
{
	return (this->toFloat() / Class.toFloat());
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	this->_nb--;
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->_nb--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	this->_nb++;
	return (old);
}

Fixed	&Fixed::operator++(void)
{
	this->_nb++;
	return (*this);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &Class)
{
	out << Class.toFloat();
	return (out);
}


int Fixed::getRawBits(void) const
{
	return (_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

int	Fixed::toInt(void) const
{
	return ((this->_nb >>this->_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << this->_bits));
}