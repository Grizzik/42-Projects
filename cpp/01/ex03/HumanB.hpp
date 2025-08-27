#ifndef HumanB_H
# define HumanB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon 		*_clubs;
public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &Type);
};


#endif//*******************************************Human_H