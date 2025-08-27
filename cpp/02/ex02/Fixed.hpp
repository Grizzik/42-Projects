/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:06:48 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/04 22:59:16 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_nb;
		static const int	_bits = 8;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &toCopy);
		~Fixed(void);

		Fixed&			operator = (const Fixed &toCopy);
		Fixed			operator + (const Fixed &fixed) const;
		Fixed			operator - (const Fixed &fixed) const;
		Fixed			operator / (const Fixed &fixed) const;
		Fixed			operator * (const Fixed &fixed) const;
		bool			operator < (const Fixed &fixed) const;
		bool			operator <= (const Fixed &fixed) const;
		bool			operator > (const Fixed &fixed) const;
		bool			operator >= (const Fixed &fixed) const;
		bool			operator == (const Fixed &fixed) const;
		bool			operator != (const Fixed &fixed) const;
		Fixed			operator ++ (int);
		Fixed			&operator ++ (void);
		Fixed			operator -- (int);
		Fixed			&operator -- (void);
		static Fixed	min(Fixed const &a, Fixed const &b);
		static Fixed	min(Fixed &a, Fixed &b);
		static Fixed	max(Fixed const &a, Fixed const &b);
		static Fixed	max(Fixed &a, Fixed &b);
		

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream	&operator << (std::ostream &out, Fixed const &fixed);

#endif