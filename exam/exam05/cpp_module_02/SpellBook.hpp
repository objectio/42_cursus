#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

class SpellBook;

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
    public:
    typedef std::pair<std::string, ASpell *> Spell;
    typedef std::map<std::string, ASpell *> Sbook;

    private:
    Sbook book;

    SpellBook(SpellBook const &s);
    SpellBook& operator=(SpellBook const &s);

    public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell * aspell);
    void forgetSpell(std::string const & spell_name);
    ASpell * createSpell(std::string const & spell_name);
};

#endif