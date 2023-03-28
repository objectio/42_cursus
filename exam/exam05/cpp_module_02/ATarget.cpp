#include "ATarget.hpp"

ATarget::ATarget() : type() {}

ATarget::ATarget(std::string new_type) : type(new_type) {}
ATarget::ATarget(ATarget const &a) : type(a.type) {}
ATarget& ATarget::operator=(ATarget const &a)
{
    this->type = a.type;
    return *this;
}

ATarget::~ATarget() {}

std::string const & ATarget::getType() const
{
    return this->type;
}

void ATarget::getHitBySpell(ASpell const &aspell) const
{
    std::cout << this->type << " has been " << aspell.getEffects() << "!" << std::endl;
}