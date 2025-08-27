/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:07:11 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 01:43:23 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ScavTrap bob("Bob");
    bob.attack("you");
    bob.takeDamage(2);
    bob.beRepaired(12);
    bob.guardGate();
    bob.guardGate();
}


// int main() 
// {
//     ScavTrap bob("Bob");
//     bob.attack("you");
//     bob.takeDamage(2);
//     bob.beRepaired(12);
//     bob.guardGate();
//     bob.guardGate();

//     ScavTrap alice("Alice");
//     alice.attack("Bob");
//     alice.takeDamage(8);
//     alice.beRepaired(5);

//     ClapTrap generic("Generic");
//     generic.attack("someone");
//     generic.takeDamage(3);
//     generic.beRepaired(8);

//     return 0;
// }

