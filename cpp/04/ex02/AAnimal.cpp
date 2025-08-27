/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 06:00:07 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 06:00:07 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal"), brain(NULL) 
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type), brain(NULL) 
{
    std::cout << "AAnimal constructor with arg called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) 
{
    *this = copy;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) 
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const 
{
    return type;
}

void AAnimal::set_type(std::string diffType) 
{
    this->type = diffType;
}
