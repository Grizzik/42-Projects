/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:28:19 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 04:45:34 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "Animal constructor with arg called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->type = copy.type;
	return(*this);
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return(type);
}

void Animal::set_type(std::string diffType)
{
	this->type = diffType;
}

void Animal::makeSound() const
{
    std::cout << "I'm an animal" << std::endl;
}