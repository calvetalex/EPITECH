/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
	#define PAPAXMASCONVEYORBELT_HPP_

	#include "IConveyorBelt.hpp"
	#include <iostream>

	class PapaXmasConveyorBelt : public IConveyorBelt {
		public:
			~PapaXmasConveyorBelt();

			AObject *pickUp();
			void putDown(AObject *);
			const bool isEmpty() const;

		protected:
			AObject *obj;
	};

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
