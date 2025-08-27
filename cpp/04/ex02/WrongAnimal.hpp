#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string);
		WrongAnimal(const WrongAnimal &);
		WrongAnimal &operator=(const WrongAnimal &);
		virtual ~WrongAnimal();
		std::string get_type() const;
		void set_type(std::string);
		void makeSound() const;
};

#endif