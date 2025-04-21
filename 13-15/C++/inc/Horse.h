#ifndef HORSE_H
#define HORSE_H

#include "PackAnimal.h"

class Horse : public PackAnimal {
public:
    Horse(const std::string& name, const std::string& birthDate);
};

#endif
