/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:10:11 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/26 15:14:49 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// La fonction uintptr_t serialize(Data *ptr) est définie. Cette fonction prend un 
// pointeur vers un objet de type Data en entrée et retourne une valeur de type uintptr_t. 
// uintptr_t est un type entier non signé capable de stocker des pointeurs sans conversion. 
// La fonction utilise reinterpret_cast pour convertir le pointeur ptr en une valeur de type 
// uintptr_t, qui représente essentiellement l'adresse mémoire à laquelle le pointeur pointe.

// La fonction Data *deserialize(uintptr_t raw) est définie. Cette fonction prend 
// une valeur de type uintptr_t en entrée et retourne un pointeur vers un objet de type Data.
// La fonction utilise reinterpret_cast pour convertir la valeur raw de type uintptr_t en un 
// pointeur de type Data *. Cela reconstitue essentiellement le pointeur original à partir de 
// la valeur sérialisée.

// int main(void)
// {
//     Data data;
//     data.str = "Hello world";	
//     std::cout << "&data : " << &data << std::endl;
// 	std::cout << std::endl;
	
//     uintptr_t serialized = Serializer::serialize(&data);
//     std::cout << "serialized :" << serialized << std::endl;
// 	std::cout << std::endl;
	
//     Data* deserialized = Serializer::deserialize(serialized);
//     std::cout << "deserialized :" << deserialized << std::endl;
// 	std::cout << std::endl;
	
	
// 	if (deserialized == &data)
//         std::cout << "Le pointeur est identique." << std::endl;
// 	else
//         std::cout << "Le pointeur n'est pas identique." << std::endl;

//     return (0);
// }

int	main(void)
{
	Data		*ptr = new Data;
	Data		*serialized;
	uintptr_t	raw;

	ptr->str = "Hello World";
	std::cout << "ptr->str : " << ptr->str << std::endl;
	std::cout << std::endl;
	
	raw = Serializer::serialize(ptr);

	serialized = Serializer::deserialize(raw);

	std::cout << "serialized->str = " << serialized->str << std::endl;
	delete (ptr);
	return (0);
}