/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:14:05 by npetitpi          #+#    #+#             */
/*   Updated: 2024/02/29 16:14:05 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _clubs(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &Type)
{
	_clubs = &Type;
}

void HumanB::attack()
{
	if (_clubs == NULL)
		std::cout << _name << " have empty hands" << std::endl;
	else
	std::cout << _name << " attacks with their " << _clubs->getType() << std::endl;
}

