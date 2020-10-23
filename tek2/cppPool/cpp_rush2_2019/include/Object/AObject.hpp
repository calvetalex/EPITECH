/*
** EPITECH PROJECT, 2020
** Abstract Object
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
    #define AOBJECT_HPP_

    #include "IObject.hpp"

    class AObject: virtual public IObject {
        public:
            AObject() {};
            AObject(Type);
            virtual ~AObject();

            const Type getType(void) const final;

    	protected:
            Type _typeObj;

        private :
    };

#endif /* !OBJECT_HPP_ */
