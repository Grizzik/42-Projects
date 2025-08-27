/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:18 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/01 12:59:24 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	public	:
		Contact get_contact(int i);
		std::string get_first_name(int i);
		std::string get_last_name(int i);
		std::string get_nickname(int i);
		std::string get_number(int i);
		std::string get_secret(int i);

		PhoneBook();
		~PhoneBook();
		
		int	FillPhoneBook(int i, std::string f, std::string l, std::string n,
		std::string nb, std::string ds);
		
	private	:
		Contact	phoneBook[8];
};

#endif//***********************************************************************PHONEBOOK_H
