/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:09:11 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/02 17:49:37 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie* ManuZombie = newZombie("Manu");
	ManuZombie->Announce();
	delete ManuZombie;

	Zombie MyZombie("Shanley");
    MyZombie.Announce();

	randomChump("Clem");
	return(0);
}
