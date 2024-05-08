/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:20:35 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 17:38:57 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_CPP
# define SED_CPP

#include <iostream>
#include <fstream>
#include <string>

bool	checkInput(std::string filename, std::string str1, std::string str2);
void	replace(std::string ifs, std::string str1, std::string str2);

#endif