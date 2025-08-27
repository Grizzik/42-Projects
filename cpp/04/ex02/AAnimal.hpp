#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
protected:
    std::string type;
    Brain *brain;
    AAnimal();

public:
    AAnimal(std::string);
    AAnimal(const AAnimal &);
    AAnimal &operator=(const AAnimal &);
    virtual ~AAnimal();
    std::string getType() const;
    void set_type(std::string);
    virtual void makeSound() const = 0;
};

#endif
