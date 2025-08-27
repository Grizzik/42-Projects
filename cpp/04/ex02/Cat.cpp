/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:28:40 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 05:58:11 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain();
}


Cat::Cat(const Cat &copy) : AAnimal(copy) 
{
    brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy) 
{
    if (this != &copy) 
	{
        AAnimal::operator=(copy);
        delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called!!" << std::endl;
    delete brain;
}
void Cat::makeSound() const
{
    std::cout << getType() << ": miaow" << std::endl;
}