/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:32:02 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 15:45:43 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++){
		if (_materias[i])
			delete _materias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			_materias[i] = rhs._materias[i];
		}
	}
	return *this;
}

void		MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return (_materias[i]->clone());
		}
	}
	return NULL;
}