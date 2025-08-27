/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:05 by npetitpi          #+#    #+#             */
/*   Updated: 2024/02/29 15:43:05 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>


int main(int ac, char **av)
{
	int			j;
	char		letter;
	std::string	str;

	if (ac == 1)
		return(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl,0);

	for (int i = 1; i < ac; i++)
	{
		j = 0;
		str = av[i];
		while (str[j])
		{
			letter = toupper((int)str[j]);
			std::cout << letter;
			j++;
		}
		if (i < ac - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}