/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:16 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/01 12:58:55 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}

std::string	Contact::GetFirstname()
{
	return (_FName);
}

std::string	Contact::GetLastname()
{
	return (_LName);
}

std::string	Contact::GetNickname()
{
	return (_NName);
}

std::string	Contact::GetNumber()
{
	return (_Number);
}

std::string	Contact::GetSecret()
{
	return (_Secret);
}

void Contact::PrintContact()
{
	std::cout << "First Name: " << this->_FName << std::endl;
	std::cout << "Last Name: " << this->_LName << std::endl;
	std::cout << "Nickname: " << this->_NName << std::endl;
	std::cout << "Phone Number: " << this->_Number << std::endl;
	std::cout << "Darkest Secret: " << this->_Secret << std::endl;
}


int	Contact::SetInfo(std::string f, std::string l, std::string n,
	std::string nb, std::string ds)
	{
		this->_FName = f;
		this->_LName = l;
		this->_NName = n;
		this->_Number = nb;
		this->_Secret = ds;
		if (_FName == "\0")
			return (std::cout << "empty category" << std::endl, 1);
		if (_LName[0] == '\0')
			return (std::cout << "empty category" << std::endl, 1);
		if (_NName[0] == '\0')
			return (std::cout << "empty category" << std::endl, 1);
		if (_Number[0] == '\0')
			return (std::cout << "empty category" << std::endl, 1);
		if (_Secret[0] == '\0')
			return (std::cout << "empty category" << std::endl, 1);
		return(0);
	}