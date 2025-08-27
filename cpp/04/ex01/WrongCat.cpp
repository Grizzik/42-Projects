/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:30:01 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 05:27:34 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	WrongAnimal::type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << "WrongCat copy constructor called!!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	return(*this);
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called!!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "maaaowww" << std::endl;
}