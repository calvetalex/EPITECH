/*
** EPITECH PROJECT, 2020
** Abstract Object
** File description:
** AObject
*/

#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_

    class IObject {
        public:
            typedef enum ObjectType {
                TEDDY,
                PONY,
                GIFTPAPER,
                BOX
            }Type;

            virtual ~IObject() = default;

            virtual const Type getType(void) const = 0;

    	protected:
            Type _typeObj;

        private :

    };

#endif /* !OBJECT_HPP_ */
