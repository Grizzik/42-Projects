/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:14:56 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/02 18:00:46 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		outfilename;
	std::ifstream	inputFile;
	std::ofstream	newfile;
	std::string		line;

	if (ac != 4)
		return(std::cout<<"Argument error"<<std::endl, 1);

	filename = av[1];
	std::cout << "Ouverture du fichier d'entrée : " << filename << std::endl;
	inputFile.open(filename.c_str());
	if (!inputFile.is_open()) 
	{
        return(std::cout << "Erreur : Impossible d'ouvrir le fichier d'entrée." << std::endl, 2);
    }
	std::cout << "Création du fichier de sortie : " << filename << ".replace" << std::endl;
	outfilename = filename + ".replace";
	newfile.open(outfilename.c_str());
	if (!newfile.is_open())
	{
		return (std::cout << "Open/Creation outfile failed" << std::endl, 3);
		inputFile.close();
	}

	std::getline(inputFile, line, '\0');
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	for (size_t index = 0; index < line.length(); index++)
	{
		if (index == line.find(s1))
		{
			line.erase(index, s1.length());
			line.insert(index, s2);
			index += s2.length();
		}
	}
	newfile << line;
	inputFile.close();
	newfile.close();
	std::cout << "Fermeture des fichiers." << std::endl;
	return (0);
}
