#ifndef ATARGET_HPP
#define ATARGET_HPP

class ATarget;

#include <string>
#include <iostream>
#include "ASpell.hpp"


class ATarget {
    protected:
    std::string type;

    public:
    ATarget();
    ATarget(std::string new_type);
    ATarget(ATarget const &a);
    ATarget& operator=(ATarget const &a);
    virtual ~ATarget();

    std::string const & getType() const;
    virtual ATarget * clone() const = 0;
    void getHitBySpell(ASpell const &aspell) const;
};

#endif