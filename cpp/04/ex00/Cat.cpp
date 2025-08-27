/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:28:40 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 04:46:34 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat"; 
    std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(const Cat &copy) 
{
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) 
{
	this->type = copy.type;
	std::cout << "Cat assignment operator called" << std::endl;
	return(*this);
}

Cat::~Cat()  
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << getType() << ": miaow" << std::endl;
}