/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:27:19 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 16:00:55 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];

	public:
		MateriaSource();
		~MateriaSource();

		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &rhs);

		void			learnMateria(AMateria *m);
		AMateria		*createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP