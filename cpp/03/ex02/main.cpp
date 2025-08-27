/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:23:44 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 01:59:25 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main () 
{
	 ScavTrap bob("Bob");
    bob.attack("you");
    bob.takeDamage(2);
    bob.beRepaired(12);
    bob.guardGate();
    bob.guardGate();
	
    FragTrap frag("Fraggy");
	frag.highFivesGuys();
    frag.attack("Bob");
    frag.beRepaired(10);
    frag.takeDamage(30);
}


// int main() {
//     // Create instances of FragTrap
//     FragTrap frag1("Frag1");
//     FragTrap frag2("Frag2");

//     // Test attack, takeDamage, and beRepaired
//     frag1.attack("Target1");
//     frag2.takeDamage(20);
//     frag2.beRepaired(10);

//     // Test guardGate and highFivesGuys
//     frag1.guardGate();
//     frag1.highFivesGuys();

//     // Test destruction order
//     {
//         FragTrap frag3("Frag3");
//     } // frag3 should be destroyed here, testing destruction order

//     // Test copy constructor and copy assignment
//     FragTrap frag4 = frag1; // copy constructor
//     FragTrap frag5("Frag5");
//     frag5 = frag2; // copy assignment

//     // Test additional attacks and damage
//     frag1.attack("Target2");
//     frag2.takeDamage(50);

//     return 0;
// }
