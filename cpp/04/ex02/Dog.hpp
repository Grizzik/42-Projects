#ifndef DOG_HPP
#define DOG_HPP


#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal 
{
public:
    Dog();
    Dog(const Dog &);
    Dog &operator=(const Dog &);
    ~Dog();
    void makeSound() const;
};

#endif