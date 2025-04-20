#include "Animal.h"

Animal::Animal(const std::string &name, const std::string &birthDate)
    : name(name), birthDate(birthDate) {}

void Animal::addCommand(const std::string &command) {
    commands.push_back(command);
}

std::vector<std::string> Animal::getCommands() const {
    return commands;
}

std::string Animal::getName() const {
    return name;
}

std::string Animal::getBirthDate() const {
    return birthDate;
}
