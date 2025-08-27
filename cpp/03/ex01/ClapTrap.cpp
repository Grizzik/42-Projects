/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:08:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 02:15:03 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    name = "nameless";
	std::cout << "[ClapTrap] default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &CopiedBy) 
{
	this->hitPoints= CopiedBy.hitPoints;
    this->energyPoints = CopiedBy.energyPoints;
    this->attackDamage = 0;
	std::cout << "[ClapTrap] copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& CopiedBy) 
{
	if (this != &CopiedBy) 
	{
        this->hitPoints= CopiedBy.hitPoints;
        this->energyPoints = CopiedBy.energyPoints;
    }
	std::cout << "[ClapTrap] copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "[ClapTrap] destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) 
{
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    this->name = _name;
}

void ClapTrap::attack(const std::string& target) 
{
    if (this->energyPoints == 0 || this->hitPoints == 0) {
        std::cout << "No energy or hit points left" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (this->hitPoints == 0) 
	{
        std::cout << "No hit points left." << std::endl;
        return;
    }
    if (this->hitPoints >= amount)
	{
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes damage and loses " << amount << " points of hit points." << std::endl;
    }
    else if (this->hitPoints < amount)
	{
        this->hitPoints = 0;
        std::cout << "ClapTrap " << name << " is dead." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (this->energyPoints == 0 || this->hitPoints == 0) 
	{
        std::cout << "No energy or hit points left." << std::endl;
        return;
    }
    this->hitPoints += amount;
    this->energyPoints--;

    std::cout << "ClapTrap " << name << " repairs itself and gets " << amount << " point of hit points." << std::endl;
}