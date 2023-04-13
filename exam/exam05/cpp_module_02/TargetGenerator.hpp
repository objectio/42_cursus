#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <iostream>
#include <string>
#include <map>

class TargetGenerator {
    public:
    typedef std::pair<std::string, ATarget *> Target;
    typedef std::map<std::string, ATarget *> Target_Book;

    private:
    Target_Book target_book;
    TargetGenerator(TargetGenerator const &t);
    TargetGenerator& operator= (TargetGenerator const &t);
    
    public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const & name);
    ATarget* createTarget(std::string const & name);
};

#endif