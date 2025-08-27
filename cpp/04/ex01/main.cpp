/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:29:23 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 05:36:23 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    const int numAnimals = 10;
    Animal *animals[numAnimals];

    for (int i = 0; i < numAnimals; i++) 
	{
        if (i < numAnimals / 2) 
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
	}
    for (int i = 0; i < numAnimals; i++) 
        animals[i]->makeSound();
    for (int i = 0; i < numAnimals; i++) 
        delete animals[i];
    return 0;
}


// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// return 0;
// }