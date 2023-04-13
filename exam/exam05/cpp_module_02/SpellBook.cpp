#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell * aspell)
{
    Sbook::iterator it = book.find(aspell->getName());
    if (it == book.end())
    {
        book.insert(Spell(aspell->getName(), aspell->clone()));
    }
}

void SpellBook::forgetSpell(std::string const & spell_name)
{
    Sbook::iterator it = book.find(spell_name);
    if (it != book.end())
    {
        delete it->second;
        book.erase(it);
    }
}

ASpell * SpellBook::createSpell(std::string const & spell_name)
{
    Sbook::iterator it = book.find(spell_name);
    if (it != book.end())
        return it->second;
    return NULL;
}