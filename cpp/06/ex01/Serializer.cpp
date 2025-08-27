/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:09:22 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/19 15:21:00 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Serializer::Serializer(void)
// {
// 	std::cout << "Serializer constructor called" << std::endl;
// 	return ;
// }

// Serializer::Serializer(Serializer const &toCopy)
// {
// 	if (this != &toCopy)
// 		*this = toCopy;
// 	std::cout << "Serializer copy constructor called" << std::endl;
// 	return ;
// }

// Serializer::~Serializer(void)
// {
// 	std::cout << "Serializer destructor called" << std::endl;
// 	return ;
// }

Serializer	&Serializer::operator = (Serializer const &toCopy)
{
	(void)toCopy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}