/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:15:43 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/04 13:28:31 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;
	std::string	input;

	std::cout << "Type : [DEBUG / INFO / WARNING / ERROR] or EXIT to quit the programm" << std::endl;
	std::getline(std::cin, input);
	while (!std::cin.eof() && input != "EXIT")
	{
		harl.complain(input);
		std::getline(std::cin, input);
	}
	return (0);
}