/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:26 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/01 12:52:16 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact
{
	public:
		std::string GetFirstname();
		std::string GetLastname();
		std::string GetNickname();
		std::string GetNumber();
		std::string GetSecret();

		Contact();
		~Contact();

		void	PrintContact();
		int	SetInfo(std::string f, std::string l, std::string n,
			std::string nb, std::string ds);
	private:
		std::string _FName;
		std::string _LName;
		std::string _NName;
		std::string _Number;
		std::string _Secret;
};

#endif //**************************************************************************** _CONTACT_H3