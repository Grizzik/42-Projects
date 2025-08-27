/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:13:51 by npetitpi          #+#    #+#             */
/*   Updated: 2024/02/29 16:13:51 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &clubs) : _name(name), _clubs(clubs)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
std::cout << _name << " attacks with their " << _clubs.getType() << std::endl;
}