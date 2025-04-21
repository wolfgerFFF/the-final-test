#ifndef DONKEY_H
#define DONKEY_H

#include "PackAnimal.h"

class Donkey : public PackAnimal
{
public:
    Donkey(const std::string &name, const std::string &birthDate);
};

#endif
