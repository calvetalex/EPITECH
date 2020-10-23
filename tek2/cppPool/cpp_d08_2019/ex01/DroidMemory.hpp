/*
** EPITECH PROJECT, 2020
** DroidMemory
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        void setFingerprint(size_t);
        void setExp(size_t);
        size_t getFingerprint(void) const { return this->Fingerprint; };
        size_t getExp(void) const { return this->Exp; };
        bool operator<<(DroidMemory&);
        bool operator>>(DroidMemory&);
        bool operator+=(DroidMemory&);
        bool operator+=(size_t&);
        DroidMemory operator+(DroidMemory&);
        DroidMemory operator+(size_t&);
    private:
        size_t Fingerprint;
        size_t Exp;
};

std::ostream& operator<<(std::ostream&, DroidMemory &);

#endif /* !DROIDMEMORY_HPP_ */
