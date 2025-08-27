/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:30:01 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 04:47:35 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called!!" << std::endl;
}


WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << "WrongCat copy constructor called!!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	std::cout << "WrongCat assignment operator called!!" << std::endl;
	return(*this);
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called!!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << getType() << ": beehhh" << std::endl;
}