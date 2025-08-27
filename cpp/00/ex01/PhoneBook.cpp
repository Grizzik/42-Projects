/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:44:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/01 12:59:13 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::get_contact(int i)
{
	return (phoneBook[i]);
}

std::string	PhoneBook::get_first_name(int i)
{
	return (phoneBook[i].GetFirstname());
}

std::string	PhoneBook::get_last_name(int i)
{
	return (phoneBook[i].GetLastname());
}

std::string	PhoneBook::get_nickname(int i)
{
	return (phoneBook[i].GetNickname());
}

std::string	PhoneBook::get_number(int i)
{
	return (phoneBook[i].GetNumber());
}

std::string	PhoneBook::get_secret(int i)
{
	return (phoneBook[i].GetSecret());
}