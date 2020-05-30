/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Owner
*/

#ifndef OWNER_HPP_
#define OWNER_HPP_

#include <cstddef>

class Owner {
    public:
        Owner(const size_t &ID);
        ~Owner();

    public:
        size_t _entityID;
};

#endif /* !OWNER_HPP_ */
