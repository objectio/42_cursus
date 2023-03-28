#ifndef ASPELL_HPP
#define ASPELL_HPP

class ASpell;

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ASpell {
    protected:
    std::string name;
    std::string effects;

    public:
    std::string getName() const;
    std::string getEffects() const;
    virtual ASpell * clone() const = 0;
    void launch(ATarget const &atarget) const;

    ASpell();
    ASpell(ASpell const &a);
    ASpell(std::string new_name, std::string new_effects);
    ASpell& operator=(ASpell const &a);
    virtual ~ASpell();
};

#endif