/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:51:57 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/05 05:08:59 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain &c);
        Brain &operator=(const Brain &);
        virtual ~Brain();
};

#endif
