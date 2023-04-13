#ifndef FWOOSH_HPP
#define FWOOSH_HPP

class Fwoosh;

#include "ASpell.hpp"

class Fwoosh : public ASpell {
    public:
    Fwoosh();
    virtual ~Fwoosh();
    ASpell * clone() const;
};

#endif