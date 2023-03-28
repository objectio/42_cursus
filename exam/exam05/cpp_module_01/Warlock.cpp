#include "Warlock.hpp"
#include <string>

std::string const & Warlock::getName() const
{
    return this->name;
}

std::string const & Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(std::string const & new_title) 
{
    this->title = new_title;
}

Warlock::Warlock(std::string new_name, std::string new_title)
{
    this->name = new_name;
    this->title = new_title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell * aspell)
{
    Sbook::iterator it = book.find(aspell->getName());
    if (it == book.end())
    {
        book.insert(Spell(aspell->getName(), aspell->clone()));
    }
}

void Warlock::forgetSpell(std::string spell_name)
{
    Sbook::iterator it = book.find(spell_name);
    if (it != book.end())
    {
        delete it->second;
        book.erase(it);
    }
}

void Warlock::launchSpell(std::string spell_name, ATarget & target)
{
    Sbook::iterator it = book.find(spell_name);
    if (it != book.end())
    {
        it->second->launch(target);
    }
}