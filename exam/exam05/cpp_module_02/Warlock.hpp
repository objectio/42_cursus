#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
    // public:
    // typedef std::pair<std::string, ASpell *> Spell;
    // typedef std::map<std::string, ASpell *> Sbook;

    private:
    std::string name;
    std::string title;
    SpellBook *book;

    Warlock();
    Warlock(Warlock const &w);
    Warlock& operator=(Warlock const &w);

    public:
    std::string const & getName() const;
    std::string const & getTitle() const;

    void setTitle(std::string const & new_title);
    Warlock(std::string new_name, std::string new_title);
    ~Warlock();

    void introduce() const;

    void learnSpell(ASpell * aspell);
    void forgetSpell(std::string spell_name);
    void launchSpell(std::string spell_name, ATarget & target);
};

#endif