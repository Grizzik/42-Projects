/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:06 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 05:39:21 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
	{
        ideas[i] = "It Ain't About How Hard You Hit. It's About How Hard You Can Get Hit And Keep Moving Forward.";
    }
    std::cout << "Default Brain constructor called!!" << std::endl;
}

Brain::~Brain() 
{
    std::cout << "Default Brain destructor called!!" << std::endl;
}

Brain::Brain(const Brain &copy) 
{
    std::cout << "Copy Brain constructor called!!" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    for (size_t i = 0; i < 100; i++)
        ideas[i] = copy.ideas[i];
    return *this;
}




