#ifndef ANIMAL_REGISTRY_H
#define ANIMAL_REGISTRY_H

#include <vector>
#include <memory>
#include "Animal.h"
#include "Counter.h"

class AnimalRegistry
{
    std::vector<std::unique_ptr<Animal>> animals;
    Counter counter;

public:
    void addAnimal(const std::string &animalType, const std::string &name, const std::string &birthDate);
    void teachCommand(int animalId, const std::string &command);
    void listCommands(int animalId) const;
    void showMenu();
};

#endif 
