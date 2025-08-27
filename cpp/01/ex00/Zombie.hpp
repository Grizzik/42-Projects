/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:09:49 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/02 17:47:00 by npetitpi         ###   ########.fr       */
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
		Zombie(const std::string& name);
		~Zombie();

		std::string getName() const;
		void	Announce();
};

Zombie* newZombie(std::string Name);
void randomChump( std::string Name);

#endif //********************************************** ZOMBIE_H