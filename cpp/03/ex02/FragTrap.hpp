/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:17:23 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 01:57:13 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ClapTrap  
{
    public:
        FragTrap();
        FragTrap(const FragTrap &a);
        FragTrap &operator=(const FragTrap &CopiedBy);
        ~FragTrap();
        FragTrap(std::string _name);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate();
		void highFivesGuys();

	private:
		unsigned int gate;
};

#endif