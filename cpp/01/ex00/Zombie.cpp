/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:09:42 by npetitpi          #+#    #+#             */
/*   Updated: 2024/02/29 16:11:59 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

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

void	Zombie::Announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


