/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:12:46 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/01 14:46:41 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(const std::string& name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->getName() << " is correctly destroyed" << std::endl;
}

std::string Zombie::getName() const
{
    return this->_name;
}

void	Zombie::SetName(std::string Name)
{
	_name = Name;
}

void	Zombie::Announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

