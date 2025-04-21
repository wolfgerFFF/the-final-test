#ifndef PACK_ANIMAL_H
#define PACK_ANIMAL_H

#include "Animal.h"

class PackAnimal : public Animal
{
public:
    PackAnimal(const std::string &name, const std::string &birthDate);
};

#endif
