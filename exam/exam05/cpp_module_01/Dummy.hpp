#ifndef DUMMY_HPP
#define DUMMY_HPP

class Dummy;

#include "ATarget.hpp"

class Dummy : public ATarget {
    public:
    Dummy();
    virtual ~Dummy();
    ATarget * clone() const;
};

#endif