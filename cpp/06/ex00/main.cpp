/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:09:17 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/21 11:22:12 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Need an argument ; char / int / float / double " << std::endl;
		return (1);
	}
	std::string	input = av[1];
	return (ScalarConverter::convert(input));
}