/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:12:56 by npetitpi          #+#    #+#             */
/*   Updated: 2024/02/29 16:12:56 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(const std::string& name);
		~Zombie();

		std::string getName() const;
		void	SetName(std::string Name);
		void	Announce();
};

void randomChump( std::string Name);
Zombie* zombieHorde( int N, std::string name);

#endif //********************************************** ZOMBIE_H