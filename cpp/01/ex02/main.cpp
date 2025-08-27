/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:13:27 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/04 13:13:37 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ()
{
	std::string phrase = "HI THIS IS BRAIN";
	std::string *stringPTR = &phrase;
	std::string &stringREF = phrase;

	std::cout << "My adress is : " << &phrase << std::endl;
	std::cout << "My adress is : " << stringPTR << std::endl;
	std::cout << "My adress is : " << &stringREF << std::endl;

	std::cout << "My value is : " << phrase << std::endl;
	std::cout << "My value is : " << *stringPTR << std::endl;
	std::cout << "My value is : " << stringREF << std::endl;

}