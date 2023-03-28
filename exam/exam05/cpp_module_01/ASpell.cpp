#include "ASpell.hpp"

std::string ASpell::getName() const
{
    return this->name;
}

std::string ASpell::getEffects() const
{
    return this->effects;
}

void ASpell::launch(ATarget const &atarget) const
{
    atarget.getHitBySpell(*this);
}

ASpell::ASpell()
{
    
}

ASpell::ASpell(ASpell const &a)
{
    this->name = a.name;
    this->effects = a.effects;
}

ASpell::ASpell(std::string new_name, std::string new_effects)
{
    this->name = new_name;
    this->effects = new_effects;
}

ASpell& ASpell::operator=(ASpell const &a)
{
    this->name = a.name;
    this->effects = a.effects;
    return *this;
}

ASpell::~ASpell() {}