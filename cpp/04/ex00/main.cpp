/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:29:23 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 04:50:09 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); // cat: miaow
        j->makeSound(); // dog: woof
        meta->makeSound(); // I'm an animal!!

        delete meta;
        delete j;
        delete i;
    }

    {
        std::cout << "\n********************** Testing Wrong ****************************\n" << std::endl;

        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();

        std::cout << meta->getType() << " ";
        meta->makeSound();

        std::cout << cat->getType() << " ";
        cat->makeSound();

        delete meta;
        delete cat;
    }

    {
        std::cout << "\n********************** Testing Assignment Operators ****************************\n" << std::endl;

        Cat cat1;
        Cat cat2;
        cat2 = cat1;

        Dog dog1;
        Dog dog2;
        dog2 = dog1;

    }

    return 0;
}
