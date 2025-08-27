/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:29:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 05:56:59 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    type = "Dog";
    std::cout << "Dog default constructor called!!" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy) 
{
    brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy) {
        
        AAnimal::operator=(copy);
        delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << getType() << ": woof" << std::endl;
}
