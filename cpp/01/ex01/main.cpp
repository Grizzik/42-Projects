/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:12:40 by npetitpi          #+#    #+#             */
/*   Updated: 2024/02/29 16:12:40 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *Cage = zombieHorde(N, "Jean-Shanley");
	for(int i = 0; i < N; i++)
		Cage[i].Announce();
	delete[] Cage;
	return(0);
}