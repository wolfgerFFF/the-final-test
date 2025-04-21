#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <vector>

class Animal
{
protected:
    std::string name;
    std::string birthDate;
    std::vector<std::string> commands;

public:
    Animal(const std::string &name, const std::string &birthDate);
    virtual ~Animal() = default;

    void addCommand(const std::string &command);
    std::vector<std::string> getCommands() const;
    std::string getName() const;
    std::string getBirthDate() const;
};

#endif 
