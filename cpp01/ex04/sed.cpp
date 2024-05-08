/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:22:38 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 17:44:05 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

bool	checkInput(std::string filename, std::string str1, std::string str2) {
	std::ifstream	file;

	file.open(filename.c_str());
	if (!file) {
		std::cout << "<" << filename << "> does not exist. Please input an existing file." << std::endl;
		return (false);
	}
	if (str1.empty()) {
		std::cout << "av[2] isn't a valid string." << std::endl;
		return (false);
	}
	if (str2.empty()) {
		std::cout << "av[3] isn't a valid string." << std::endl;
		return (false);
	}
	return (true);
}

void	replace(std::string ifs, std::string str1, std::string str2) {
	//Create file
	std::string		outFileName = std::string(ifs) + ".replace";
	std::ofstream	outFile(outFileName.c_str());

	//Open file
	std::ifstream	inFile;
	inFile.open(std::string(ifs).c_str());

	//Copy file content and replace av[2] with av[3]
	if (inFile.is_open() && outFile.is_open()) {
		std::string	line;
		if (std::getline(inFile, line, '\0')) {
			size_t	pos = line.find(str1);
			while (pos != std::string::npos) {
				line.erase(pos, str1.length());
				line.insert(pos, str2);
				pos = line.find(str1);
			}
			outFile << line;
			outFile.close();
		}
		else
			std::cout << "File " << ifs << " is empty." << std::endl;
	}
}
