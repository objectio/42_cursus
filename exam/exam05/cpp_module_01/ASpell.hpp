#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class Aspell
{
    protected:
    std::string name;
    std::string effects;

    public:
    Aspell();
    virtual ~Aspell();
    Aspell(Aspell const &other);
    Aspell &operator=(Aspell const &other);
    std::string getName();
    std::string getEffects();

    virtual Aspell *clone() const = 0;

    Aspell(std::string name, std::string effects);
};

#endif