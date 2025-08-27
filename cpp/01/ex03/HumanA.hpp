#ifndef HumanA_H
# define HumanA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon 		&_clubs;
public:
	HumanA(std::string name, Weapon &clubs);
	~HumanA();
	void attack();
};

#endif//*******************************************HumanA_H